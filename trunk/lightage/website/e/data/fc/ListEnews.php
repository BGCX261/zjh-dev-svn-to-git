<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ϣ</title>
<link href="../data/menu/menu.css" rel="stylesheet" type="text/css">
<script src="../data/menu/menu.js" type="text/javascript"></script>
<script language="javascript" src="../data/rightmenu/context_menu.js"></script>
<script language="javascript" src="../data/rightmenu/ieemu.js"></script>
<SCRIPT lanuage="JScript">
if(self==top)
{self.location.href='admin.php';}

function chft(obj,ecms,classid){
	if(ecms==1)
	{
		obj.style.fontWeight='bold';
	}
	else
	{
		obj.style.fontWeight='';
	}
	obj.title='��ĿID��'+classid;
}

function tourl(bclassid,classid){
	parent.main.location.href="ListNews.php?bclassid="+bclassid+"&classid="+classid;
}

if(moz) {
	extendEventObject();
	extendElementModel();
	emulateAttachEvent();
}
//�Ҽ��˵�
function ShRM(obj,bclassid,classid,classurl,showmenu)
{
  var eobj,popupoptions;
  classurl='/e/public/ClassUrl/?classid='+classid;
if(showmenu==1)
{
  popupoptions = [
    new ContextItem("������Ϣ",function(){ parent.document.main.location="AddNews.php?enews=AddNews&bclassid="+bclassid+"&classid="+classid; }),
	new ContextSeperator(),
    new ContextItem("ˢ����Ŀ",function(){ parent.document.main.location="enews.php?enews=ReListHtml&classid="+classid; }),
	new ContextItem("ˢ����ĿJS",function(){ parent.document.main.location="ecmschtml.php?enews=ReSingleJs&doing=0&classid="+classid; }),
    new ContextItem("ˢ����ҳ",function(){ parent.document.main.location="ecmschtml.php?enews=ReIndex"; }),
	new ContextSeperator(),
	new ContextItem("Ԥ����ҳ",function(){ window.open("../../"); }),
    new ContextItem("Ԥ����Ŀ",function(){ window.open(classurl); }),
	new ContextSeperator(),
	new ContextItem("�޸���Ŀ",function(){ parent.document.main.location="AddClass.php?classid="+classid+"&enews=EditClass"; }),
    new ContextItem("��������Ŀ",function(){ parent.document.main.location="AddClass.php?enews=AddClass"; }),
    new ContextItem("������Ŀ",function(){ parent.document.main.location="AddClass.php?classid="+classid+"&enews=AddClass&docopy=1"; }),
    new ContextSeperator(),
	new ContextItem("���ݸ���",function(){ parent.document.main.location="ReHtml/ChangeData.php"; }),
	new ContextItem("���Ӳɼ��ڵ�",function(){ parent.document.main.location="AddInfoClass.php?enews=AddInfoClass&newsclassid="+classid; }),
	new ContextItem("������",function(){ parent.document.main.location="file/ListFile.php?type=9&classid="+classid; }),
	new ContextSeperator()
  ]
}
else if(showmenu==2)
{
	popupoptions = [
    new ContextItem("����ϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=news"; }),new ContextItem("����ϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=download"; }),new ContextItem("ͼƬϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=photo"; }),new ContextSeperator(),new ContextItem("FLASHϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=flash"; }),new ContextItem("��Ӱϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=movie"; }),new ContextItem("�̳�ϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=shop"; }),new ContextSeperator(),new ContextItem("����ϵͳ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=article"; }),new ContextItem("������Ϣ���ݱ�",function(){ parent.document.main.location="ListAllInfo.php?tbname=info"; })  ]
}
else
{
	popupoptions = [
    new ContextItem("ˢ����Ŀ",function(){ parent.document.main.location="enews.php?enews=ReListHtml&classid="+classid; }),
	new ContextItem("ˢ����ĿJS",function(){ parent.document.main.location="ecmschtml.php?enews=ReSingleJs&doing=0&classid="+classid; }),
    new ContextItem("ˢ����ҳ",function(){ parent.document.main.location="ecmschtml.php?enews=ReIndex"; }),
	new ContextItem("���ݸ���",function(){ parent.document.main.location="ReHtml/ChangeData.php"; }),
	new ContextSeperator(),
	new ContextItem("Ԥ����ҳ",function(){ window.open("../../"); }),
	new ContextItem("Ԥ����Ŀ",function(){ window.open(classurl); }),
	new ContextSeperator(),
	new ContextItem("�޸���Ŀ",function(){ parent.document.main.location="AddClass.php?classid="+classid+"&enews=EditClass"; }),
    new ContextItem("��������Ŀ",function(){ parent.document.main.location="AddClass.php?enews=AddClass"; }),
    new ContextItem("������Ŀ",function(){ parent.document.main.location="AddClass.php?classid="+classid+"&enews=AddClass&docopy=1"; }),
	new ContextSeperator()
  ]
}
  ContextMenu.display(popupoptions)
}
</SCRIPT>
</head>
<body onLoad="initialize();ContextMenu.intializeContextMenu();" bgcolor="#FFCFAD">
	<table border='0' cellspacing='0' cellpadding='0'>
	<tr height=20>
			<td id="home"><img src="../data/images/homepage.gif" border=0></td>
			<td><a href="#ecms" onclick="parent.main.location.href='ListAllInfo.php';" onmouseout="this.style.fontWeight=''" onmouseover="this.style.fontWeight='bold'" oncontextmenu="ShRM(this,0,0,'',2)"><b>������Ϣ</b></a></td>
	</tr>
	</table>
	<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr1" class="file" onclick=""><a onclick=tourl(0,1) onmouseout=chft(this,0,1) onmouseover=chft(this,1,1) oncontextmenu=ShRM(this,0,1,'',1)>��վ��ҳ</a></td>
		  </tr>
				<tr>
			<td id="pr2" class="file" onclick=""><a onclick=tourl(0,2) onmouseout=chft(this,0,2) onmouseover=chft(this,1,2) oncontextmenu=ShRM(this,0,2,'',1)>��������</a></td>
		  </tr>
				<tr>
			<td id="pr3" class="menu1" onclick="chengstate('3')"><a onmouseout=chft(this,0,3) onmouseover=chft(this,1,3) oncontextmenu=ShRM(this,0,3,'',0)>��Ʒ����</a></td>
		  </tr>
				  <tr id="item3" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr7" class="menu1" onclick="chengstate('7')"><a onmouseout=chft(this,0,7) onmouseover=chft(this,1,7) oncontextmenu=ShRM(this,3,7,'',0)>дʵ���</a></td>
		  </tr>
				  <tr id="item7" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr14" class="file" onclick=""><a onclick=tourl(7,14) onmouseout=chft(this,0,14) onmouseover=chft(this,1,14) oncontextmenu=ShRM(this,7,14,'',1)>�й���</a></td>
		  </tr>
				<tr>
			<td id="pr15" class="file" onclick=""><a onclick=tourl(7,15) onmouseout=chft(this,0,15) onmouseover=chft(this,1,15) oncontextmenu=ShRM(this,7,15,'',1)>ŷ����</a></td>
		  </tr>
				<tr>
			<td id="pr16" class="file1" onclick=""><a onclick=tourl(7,16) onmouseout=chft(this,0,16) onmouseover=chft(this,1,16) oncontextmenu=ShRM(this,7,16,'',1)>����</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr8" class="file" onclick=""><a onclick=tourl(3,8) onmouseout=chft(this,0,8) onmouseover=chft(this,1,8) oncontextmenu=ShRM(this,3,8,'',1)>��ͨ���</a></td>
		  </tr>
				<tr>
			<td id="pr9" class="file" onclick=""><a onclick=tourl(3,9) onmouseout=chft(this,0,9) onmouseover=chft(this,1,9) oncontextmenu=ShRM(this,3,9,'',1)>Ψ�����</a></td>
		  </tr>
				<tr>
			<td id="pr10" class="file" onclick=""><a onclick=tourl(3,10) onmouseout=chft(this,0,10) onmouseover=chft(this,1,10) oncontextmenu=ShRM(this,3,10,'',1)>�廭</a></td>
		  </tr>
				<tr>
			<td id="pr11" class="menu1" onclick="chengstate('11')"><a onmouseout=chft(this,0,11) onmouseover=chft(this,1,11) oncontextmenu=ShRM(this,3,11,'',0)>����</a></td>
		  </tr>
				  <tr id="item11" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr12" class="file1" onclick=""><a onclick=tourl(11,12) onmouseout=chft(this,0,12) onmouseover=chft(this,1,12) oncontextmenu=ShRM(this,11,12,'',1)>С������</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr13" class="file1" onclick=""><a onclick=tourl(3,13) onmouseout=chft(this,0,13) onmouseover=chft(this,1,13) oncontextmenu=ShRM(this,3,13,'',1)>3Dģ��</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr4" class="file" onclick=""><a onclick=tourl(0,4) onmouseout=chft(this,0,4) onmouseover=chft(this,1,4) oncontextmenu=ShRM(this,0,4,'',1)>ҵ��Χ</a></td>
		  </tr>
				<tr>
			<td id="pr5" class="file" onclick=""><a onclick=tourl(0,5) onmouseout=chft(this,0,5) onmouseover=chft(this,1,5) oncontextmenu=ShRM(this,0,5,'',1)>��Ƹ�˲�</a></td>
		  </tr>
				<tr>
			<td id="pr6" class="file" onclick=""><a onclick=tourl(0,6) onmouseout=chft(this,0,6) onmouseover=chft(this,1,6) oncontextmenu=ShRM(this,0,6,'',1)>��ϵ����</a></td>
		  </tr>
				<tr>
			<td id="pr17" class="menu1" onclick="chengstate('17')"><a onmouseout=chft(this,0,17) onmouseover=chft(this,1,17) oncontextmenu=ShRM(this,0,17,'',0)>HOME</a></td>
		  </tr>
				  <tr id="item17" style="display:none">
			<td class="list">
						</td>
		 </tr>	
				<tr>
			<td id="pr18" class="file" onclick=""><a onclick=tourl(0,18) onmouseout=chft(this,0,18) onmouseover=chft(this,1,18) oncontextmenu=ShRM(this,0,18,'',1)>ABOUT US</a></td>
		  </tr>
				<tr>
			<td id="pr19" class="menu1" onclick="chengstate('19')"><a onmouseout=chft(this,0,19) onmouseover=chft(this,1,19) oncontextmenu=ShRM(this,0,19,'',0)>GALLERY</a></td>
		  </tr>
				  <tr id="item19" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr23" class="menu1" onclick="chengstate('23')"><a onmouseout=chft(this,0,23) onmouseover=chft(this,1,23) oncontextmenu=ShRM(this,19,23,'',0)>Realist Style</a></td>
		  </tr>
				  <tr id="item23" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr28" class="file" onclick=""><a onclick=tourl(23,28) onmouseout=chft(this,0,28) onmouseover=chft(this,1,28) oncontextmenu=ShRM(this,23,28,'',1)>Chinese Style</a></td>
		  </tr>
				<tr>
			<td id="pr29" class="file" onclick=""><a onclick=tourl(23,29) onmouseout=chft(this,0,29) onmouseover=chft(this,1,29) oncontextmenu=ShRM(this,23,29,'',1)>Western Style</a></td>
		  </tr>
				<tr>
			<td id="pr30" class="file1" onclick=""><a onclick=tourl(23,30) onmouseout=chft(this,0,30) onmouseover=chft(this,1,30) oncontextmenu=ShRM(this,23,30,'',1)>Scene</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr24" class="file" onclick=""><a onclick=tourl(19,24) onmouseout=chft(this,0,24) onmouseover=chft(this,1,24) oncontextmenu=ShRM(this,19,24,'',1)>Cartoon style</a></td>
		  </tr>
				<tr>
			<td id="pr25" class="file" onclick=""><a onclick=tourl(19,25) onmouseout=chft(this,0,25) onmouseover=chft(this,1,25) oncontextmenu=ShRM(this,19,25,'',1)>Aesthetic style</a></td>
		  </tr>
				<tr>
			<td id="pr26" class="file" onclick=""><a onclick=tourl(19,26) onmouseout=chft(this,0,26) onmouseover=chft(this,1,26) oncontextmenu=ShRM(this,19,26,'',1)>Illustration</a></td>
		  </tr>
				<tr>
			<td id="pr27" class="menu1" onclick="chengstate('27')"><a onmouseout=chft(this,0,27) onmouseover=chft(this,1,27) oncontextmenu=ShRM(this,19,27,'',0)>Comic</a></td>
		  </tr>
				  <tr id="item27" style="display:none">
			<td class="list">
				<table border=0 cellspacing=0 cellpadding=0>
			<tr>
			<td id="pr32" class="file1" onclick=""><a onclick=tourl(27,32) onmouseout=chft(this,0,32) onmouseover=chft(this,1,32) oncontextmenu=ShRM(this,27,32,'',1)>Yueyun</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr31" class="file1" onclick=""><a onclick=tourl(19,31) onmouseout=chft(this,0,31) onmouseover=chft(this,1,31) oncontextmenu=ShRM(this,19,31,'',1)>3D model</a></td>
		  </tr>
			</table>
				</td>
		 </tr>	
				<tr>
			<td id="pr20" class="file" onclick=""><a onclick=tourl(0,20) onmouseout=chft(this,0,20) onmouseover=chft(this,1,20) oncontextmenu=ShRM(this,0,20,'',1)>OFFERINGS</a></td>
		  </tr>
				<tr>
			<td id="pr21" class="file" onclick=""><a onclick=tourl(0,21) onmouseout=chft(this,0,21) onmouseover=chft(this,1,21) oncontextmenu=ShRM(this,0,21,'',1)>CAREER</a></td>
		  </tr>
				<tr>
			<td id="pr22" class="file1" onclick=""><a onclick=tourl(0,22) onmouseout=chft(this,0,22) onmouseover=chft(this,1,22) oncontextmenu=ShRM(this,0,22,'',1)>CONTACT US</a></td>
		  </tr>
			</table>
	</body>
</html>
