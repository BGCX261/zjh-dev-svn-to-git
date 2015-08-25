package com.heyang.common.gui.intro;

import java.awt.Color;
import java.awt.Dimension;

import javax.swing.JLabel;

/**
 * �̳���IntroBase��,���������������Ǳ�ǩ
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:34
 */
public class IntroLabel extends IntroBase{
	private static final long serialVersionUID = -245353828300108L;

	/**
	 * IntroLabel���캯��
	 * @param introduction
	 */
	public IntroLabel(String introduction){
		// ���ø��๹�캯��
		super(introduction);
		
		component=new JLabel();
		
		Dimension labelDimension = new Dimension(160, 20);
		component.setMaximumSize(labelDimension);
		component.setMinimumSize(labelDimension);
		component.setPreferredSize(labelDimension);
	
		// ���ø������ò��ֲ����������ĺ���
		setLayoutAndAddComponents();
	}
	
	/**
	 * �����û�����
	 * @param introduction
	 * @param value
	 */
	public IntroLabel(String introduction,String value){
		// ���ø��๹�캯��
		this(introduction);
		setText(value);
	}
	
	/**
	 * ȡ��JTextField���û����������,��IntroBase��ǿ��ʵ�ֵĺ���
	 */
	public String getText(){
		JLabel ctrl=(JLabel)component;
		
		return ctrl.getText();
	}
	
	/**
	 * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setFocus(){
		
	}
	
	/**
	 * ����textField�е�����,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setText(String text){
		JLabel ctrl=(JLabel)component;
		ctrl.setText(text);
	}
	
	public JLabel getRightLabel() {
        JLabel ctrl = (JLabel) component;
        return ctrl;
    }
	
	public void setColors(Color bgColor,Color leftForeColor,Color rightForeColor){
		this.setBackground(bgColor);		
		introLbl.setForeground(leftForeColor);
		
		JLabel ctrl=(JLabel)component;
		ctrl.setForeground(rightForeColor);
	}
	
	public void setRightForeColor(Color rightForeColor){
		JLabel ctrl=(JLabel)component;
		ctrl.setForeground(rightForeColor);
	}
	
	public void setRightBackgroundColor(Color rightForeColor){
		JLabel ctrl=(JLabel)component;
		ctrl.setBackground(rightForeColor);
	}
	
	public void setLeftDemension(Dimension dm){
		introLbl.setMaximumSize(dm);
		introLbl.setMinimumSize(dm);
		introLbl.setPreferredSize(dm);
	}
	
	public void setRightDemension(Dimension dm){
		JLabel ctrl=(JLabel)component;
		
		ctrl.setMaximumSize(dm);
		ctrl.setMinimumSize(dm);
		ctrl.setPreferredSize(dm);
	}
}