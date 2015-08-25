function DrawImage(ImgD,FitWidth,FitHeight){
	var image=new Image();
	image.src=ImgD.src;
	if(image.width>0 && image.height>0){
		if(image.width/image.height>= FitWidth/FitHeight){
			if(image.width>FitWidth){
				ImgD.width=FitWidth;
				ImgD.height=(image.height*FitWidth)/image.width;
			}else{
					ImgD.width=image.width;
					ImgD.height=image.height;
			}
		}else{
				if(image.height>FitHeight){
					ImgD.height=FitHeight;
					ImgD.width=(image.width*FitHeight)/image.height;
				}else{
						ImgD.width=image.width;
						ImgD.height=image.height;
				}
		}
	}
}
function ImageSize(ContentID,maxWidth,maxHeight)
{
	var div=document.getElementById(ContentID);
	var img=div.getElementsByTagName("img");
	for(var i=0;i<img.length;i++)
	{
		if(img.item(i).width>maxWidth || img.item(i).height>maxHeight)
		{
			DrawImage(img.item(i),maxWidth,maxHeight)
		}
	}
}