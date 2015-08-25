package com.heyang.common.gui.intro;

import java.awt.Color;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JPasswordField;
import javax.swing.text.JTextComponent;

/**
 * �̳���IntroBase��,���������������ǵ��������
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:34
 */
public class IntroPassword extends IntroBase implements FocusListener {
	private static final long serialVersionUID = -2867677661828300108L;

	/**
	 * IntroText���캯��
	 * @param introduction
	 */
	public IntroPassword(String introduction){
		// ���ø��๹�캯��
		super(introduction);
		
		// ��componentʵ��ɵ����ı���,������ʵ�ֱ仯�Ĺؼ�����
		component=new JPasswordField();
		component.addFocusListener(this);
	
		// ���ø������ò��ֲ����������ĺ���
		setLayoutAndAddComponents();
	}
	
	/**
	 * ȡ��JTextField���û����������,��IntroBase��ǿ��ʵ�ֵĺ���
	 */
	@SuppressWarnings("deprecation")
	public String getText(){
		JPasswordField textField=(JPasswordField)component;
		
		return textField.getText();
	}
	
	/**
	 * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setFocus(){
		JPasswordField textField=(JPasswordField)component;
		textField.requestFocus();
	}
	
	/**
	 * ����textField�е�����,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setText(String text){
		JPasswordField textField=(JPasswordField)component;
		textField.setText(text);
	}
	
	/**
	 * �õ��ı��������
	 * 
	 * @author������
	 * @date��2009-12-21
	 * @time������09:56:02
	 * @return
	 */
	public JTextComponent getJTextComponent(){
		JPasswordField textField=(JPasswordField)component;
		
		return textField;
	}
	
	@Override
	public void focusGained(FocusEvent arg0) {
		component.setBackground(Color.LIGHT_GRAY);
		
	}

	@Override
	public void focusLost(FocusEvent arg0) {
		component.setBackground(Color.white);
		
	}
}