// JavaScript Document
var $11 = function (id) {
	return "string" == typeof id ? document.getElementById(id) : id;
};

var Class = {
  create: function() {
	return function() {
	  this.initialize.apply(this, arguments);
	}
  }
}

Object.extend = function(destination, source) {
	for (var property in source) {
		destination[property] = source[property];
	}
	return destination;
}

var TransformView = Class.create();
TransformView.prototype = {
  //��������,��������,�л�����,�л�����
  initialize: function(phototop, slider, parameter, count, options) {
	if(parameter <= 0 || count <= 0) return;
	var oPhototop = $11(phototop), oSlider = $11(slider), oThis = this;

	this.Index = 0;//��ǰ����
	
	this._timer = null;//��ʱ��
	this._slider = oSlider;//��������
	this._parameter = parameter;//�л�����
	this._count = count || 0;//�л�����
	this._target = 0;//Ŀ�����
	
	this.SetOptions(options);
	
	this.Up = !!this.options.Up;
	this.Step = Math.abs(this.options.Step);
	this.Time = Math.abs(this.options.Time);
	this.Auto = !!this.options.Auto;
	this.Pause = Math.abs(this.options.Pause);
	this.onStart = this.options.onStart;
	this.onFinish = this.options.onFinish;
	
	oPhototop.style.overflow = "hidden";
	oPhototop.style.position = "relative";
	
	oSlider.style.position = "absolute";
	oSlider.style.top = oSlider.style.left = 0;
  },
  //����Ĭ������
  SetOptions: function(options) {
	this.options = {//Ĭ��ֵ
		Up:			true,//�Ƿ�����(��������)
		Step:		5,//�����仯��
		Time:		10,//������ʱ
		Auto:		true,//�Ƿ��Զ�ת��
		Pause:		10000,//ͣ��ʱ��(AutoΪtrueʱ��Ч)
		onStart:	function(){},//��ʼת��ʱִ��
		onFinish:	function(){}//���ת��ʱִ��
	};
	Object.extend(this.options, options || {});
  },
  //��ʼ�л�����
  Start: function() {
	if(this.Index < 0){
		this.Index = this._count - 1;
	} else if (this.Index >= this._count){ this.Index = 0; }
	
	this._target = -1 * this._parameter * this.Index;
	this.onStart();
	this.Move();
  },
  //�ƶ�
  Move: function() {
	clearTimeout(this._timer);
	var oThis = this, style = this.Up ? "top" : "left", iNow = parseInt(this._slider.style[style]) || 0, iStep = this.GetStep(this._target, iNow);
	
	if (iStep != 0) {
		this._slider.style[style] = (iNow + iStep) + "px";
		this._timer = setTimeout(function(){ oThis.Move(); }, this.Time);
	} else {
		this._slider.style[style] = this._target + "px";
		this.onFinish();
		if (this.Auto) { this._timer = setTimeout(function(){ oThis.Index++; oThis.Start(); }, this.Pause); }
	}
  },
  //��ȡ����
  GetStep: function(iTarget, iNow) {
	var iStep = (iTarget - iNow) / this.Step;
	if (iStep == 0) return 0;
	if (Math.abs(iStep) < 1) return (iStep > 0 ? 1 : -1);
	return iStep;
  },
  //ֹͣ
  Stop: function(iTarget, iNow) {
	clearTimeout(this._timer);
	this._slider.style[this.Up ? "top" : "left"] = this._target + "px";
  }
};

function playphototop(){
	function Each(list, fun){
		for (var i = 0, len = list.length; i < len; i++) { fun(list[i], i); }
	};
	
	var objs = $11("idNum").getElementsByTagName("li");
	
	var tv = new TransformView("idTransformView", "idSlider", 300, 5, {
		onStart : function(){ Each(objs, function(o, i){ o.className = tv.Index == i ? "on" : ""; }) }//��ť��ʽ
	});
	
	tv.Start();
	
	Each(objs, function(o, i){
		o.onmouseover = function(){
			o.className = "on";
			tv.Auto = false;
			tv.Index = i;
			tv.Start();
		}
		o.onmouseout = function(){
			o.className = "";
			tv.Auto = true;
			tv.Start();
		}
	})
}
playphototop();



 //PNG  correctly handle PNG transparency in Win IE 5.5 & 6. 
function correctPNG() 

{ 

    var arVersion = navigator.appVersion.split("MSIE") 

    var version = parseFloat(arVersion[1]) 

    if ((version >= 5.5) && (document.body.filters)) 

    { 

       for(var j=0; j<document.images.length; j++) 

       { 

          var img = document.images[j] 

          var imgName = img.src.toUpperCase() 

          if (imgName.substring(imgName.length-3, imgName.length) == "PNG") 

          { 

             var imgID = (img.id) ? "id='" + img.id + "' " : "" 

             var imgClass = (img.className) ? "class='" + img.className + "' " : "" 

             var imgTitle = (img.title) ? "title='" + img.title + "' " : "title='" + img.alt + "' " 

             var imgStyle = "display:inline-block;" + img.style.cssText 

             if (img.align == "left") imgStyle = "float:left;" + imgStyle 

             if (img.align == "right") imgStyle = "float:right;" + imgStyle 

             if (img.parentElement.href) imgStyle = "cursor:hand;" + imgStyle 

             var strNewHTML = "<span " + imgID + imgClass + imgTitle 

             + " style=\"" + "width:" + img.width + "px; height:" + img.height + "px;" + imgStyle + ";" 

             + "filter:progid:DXImageTransform.Microsoft.AlphaImageLoader" 

             + "(src=\'" + img.src + "\', sizingMethod='scale');\"></span>" 

             img.outerHTML = strNewHTML 

             j = j-1 

          } 

       } 

    }     

} 

window.attachEvent("onload", correctPNG); 
