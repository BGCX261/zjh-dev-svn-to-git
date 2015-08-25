#include "UIFont.h"
#include "../Common/GOS.h"
#include "../Common/GameObjectCreation.h"

const tchar FNTHEADERTAG[] = CTEXT("[HGEFONT]");
const tchar FNTBITMAPTAG[] = CTEXT("Bitmap");
const tchar FNTCHARTAG[]   = CTEXT("Char");

UIFont::UIFont()
{
}


UIFont::~UIFont()
{
}


tchar *_get_line(tchar *file, tchar *line)
{
	int32 i=0;

	if(!file[i]) return 0;

	while(file[i] && file[i]!=CTEXT('\n') && file[i]!=CTEXT('\r'))
	{
		line[i]=file[i];
		i++;
	}
	line[i]=0;

	while(file[i] && (file[i]==CTEXT('\n') || file[i]==CTEXT('\r'))) i++;

	return file + i;
}


// Create a font object from sFileName specified
bool UIFont::Create(const tchar* sFileName)
{
	if(NULL == sFileName)
	{
		return false;
	}

	void	*data;
	uint32	size;
	tchar	*desc, *pdesc;
	tchar	linebuf[256];
	tchar	buf[GT_PATH_MAX_LEN], *pbuf;
	tchar	chr;
	int32	i, x, y, w, h, a, c;

	// Setup variables
	fHeight = 0.0f;
	//fScale = 1.0f;
	fProportion = 1.0f;
	//fRot = 0.0f;
	fTracking = 0.0f;
	fSpacing = 1.0f;
	m_pTexture = NULL;

	fZ = 0.5f;
	//nBlend=BLEND_COLORMUL | BLEND_ALPHABLEND | BLEND_NOZWRITE;
	dwCol = 0xFFFFFFFF;

	ClearMemory(&letters, sizeof(letters));
	ClearMemory(&pre, sizeof(pre));
	ClearMemory(&post, sizeof(post));
	
	// Load font description
	data = GOS::LoadFileIntoMemory(sFileName, &size);
	if(NULL == data)
	{
		return false;
	}

	desc = new tchar[size+1];
	memcpy(desc,data,size);
	desc[size]=0;
	free(data);

	pdesc = _get_line(desc,linebuf);
	if(StringCmp(linebuf, FNTHEADERTAG))
	{
		delete[] desc;	
		return false;
	}

	// Parse font description

	while((pdesc = _get_line(pdesc,linebuf)))
	{
		if(!StringNCmp(linebuf, FNTBITMAPTAG, sizeof(FNTBITMAPTAG)-1 ))
		{
			StringCopy(buf, sFileName);
			pbuf = Strrchr(buf,CTEXT('\\'));
			if(!pbuf) pbuf = Strrchr(buf,CTEXT('/'));
			if(!pbuf) pbuf = buf;
			else pbuf++;
			if(!tsscanf(linebuf, CTEXT("Bitmap = %s"), pbuf)) continue;

			//m_pTexture = GameObjectCreation::CreateTexture2D(buf);
			if(NULL == m_pTexture)
			{
				delete[] desc;	
				return false;
			}
		}
		else if(!StringNCmp(linebuf, FNTCHARTAG, sizeof(FNTCHARTAG)-1 ))
		{
			pbuf = Strrchr(linebuf,CTEXT('='));
			if(!pbuf) continue;
			pbuf++;
			while(*pbuf==CTEXT(' ')) pbuf++;
			if(*pbuf==CTEXT('\"'))
			{
				pbuf++;
				i=*pbuf++;
				pbuf++; // skip "
			}
			else
			{
				i=0;
				while((*pbuf>=CTEXT('0') && *pbuf<=CTEXT('9')) ||
					(*pbuf>=CTEXT('A') && *pbuf<=CTEXT('F')) ||
					(*pbuf>=CTEXT('a') && *pbuf<=CTEXT('f')))
				{
					chr=*pbuf;
					if(chr >= CTEXT('a')) chr-=CTEXT('a')-CTEXT(':');
					if(chr >= CTEXT('A')) chr-=CTEXT('A')-CTEXT(':');
					chr-=CTEXT('0');
					if(chr>0xF) chr=0xF;
					i=(i << 4) | chr;
					pbuf++;
				}
				if(i<0 || i>255) continue;
			}
			tsscanf(pbuf, CTEXT(" , %d , %d , %d , %d , %d , %d"), &x, &y, &w, &h, &a, &c);

			letters[i].x = x;
			letters[i].y = y;
			letters[i].w = w;
			letters[i].h = h;

			pre[i]=(float)a;
			post[i]=(float)c;
			if(h>fHeight) fHeight=(float)h;
		}
	}

	delete[] desc;	

	return true;
}


float UIFont::GetStringWidth(const tchar *string, const float fHScale, bool bMultiline) const
{
	if(NULL == string)
	{
		return 0.0f;
	}

	int32 i;
	float linew, w = 0;

	while(*string)
	{
		linew = 0;

		while(*string && *string != '\n')
		{
			i=(uint8)*string;
			linew += letters[i].w + pre[i] + post[i] + fTracking;
			string++;
		}

		if(!bMultiline) return linew*fHScale*fProportion;

		if(linew > w) w = linew;

		while (*string == '\n' || *string == '\r') string++;
	}

	return w*fHScale*fProportion;
}


void UIFont::DrawString(float x,
						float y,
						int32 align,
						const tchar *string,
						uint32 color,
						float rot,
						float fHScale,
						float fVScale)
{
	if(NULL == string)
	{
		return;
	}

	int32 i;
	float fx = x;

	align &= GTEXT_HORZMASK;
	if(align == GTEXT_RIGHT) fx -= GetStringWidth(string, fHScale, false);
	if(align == GTEXT_CENTER) fx -= int(GetStringWidth(string, fHScale, false)/2.0f);

	while(*string)
	{
		if(*string=='\n')
		{
			y += int32(fHeight*fVScale*fSpacing);
			fx = x;
			if(align == GTEXT_RIGHT)  fx -= GetStringWidth(string+1, fHScale, false);
			if(align == GTEXT_CENTER) fx -= int(GetStringWidth(string+1, fHScale, false)/2.0f);
		}
		else
		{
			i=(unsigned char)*string;

			fx += pre[i]*fHScale*fProportion;
			//letters[i]->RenderEx(fx, y, fRot, fScale*fProportion, fScale);
			m_pTexture->RenderRect(
				fx,
				y,
				(float)letters[i].x,
				(float)letters[i].y,
				(float)letters[i].w,
				(float)letters[i].h,
				color,
				rot,
				fHScale,
				fVScale
				);
			fx += (letters[i].w+post[i]+fTracking)*fHScale*fProportion;
		}
		string++;
	}
}


void UIFont::DrawString(float x, float y, int32 align, const tchar *string, const uint32 color)
{
	DrawString(x, y, align, string, color, 0.0f, 1.0f, 1.0f);
}

void UIFont::Release(void)
{
	if(m_pTexture)
	{
		//GameObjectCreation::ReleaseTexture2D(&m_pTexture);
		m_pTexture = NULL;
	}

	delete this;

	return;
}
