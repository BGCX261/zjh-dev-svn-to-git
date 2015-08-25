package com.heyang.common.gui.intro;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.text.JTextComponent;

/**
 * �̳���IntroBase��,���������������Ƕ����ı���
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:34
 */
public class IntroTextArea extends IntroBase implements FocusListener {
	private static final long serialVersionUID = -2867677661828300108L;
	
	private JTextArea textArea;

	/**
	 * IntroText���캯��
	 * @param introduction
	 */
	public IntroTextArea(String introduction){
		// ���ø��๹�캯��
		super(introduction);
		
		// 
		textArea=new JTextArea("");
//		textArea.setTabSize(8);
		textArea.setWrapStyleWord(false);
		textArea.setLineWrap(true);
		textArea.addFocusListener(this);
		
		JScrollPane jsp=new JScrollPane(textArea);
		component=jsp;
	
		// ���ø������ò��ֲ����������ĺ���
		setLayoutAndAddComponents();
		component.setPreferredSize(new Dimension(130, 100));
		
	}
	
	/**
	 * ȡ��JTextField���û����������,��IntroBase��ǿ��ʵ�ֵĺ���
	 */
	@SuppressWarnings("deprecation")
	public String getText(){
		JTextArea textField=textArea;
		
		return textField.getText();
	}
	
	/**
	 * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setFocus(){
		JTextArea textField=textArea;
		textField.requestFocus();
	}
	
	/**
	 * ����textField�е�����,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setText(String text){
		JTextArea textField=textArea;
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
		//JTextField textField=(JTextField)component;
		
		return textArea;
	}
	
	@Override
	public void focusGained(FocusEvent arg0) {
		textArea.setBackground(Color.LIGHT_GRAY);
		
	}

	@Override
	public void focusLost(FocusEvent arg0) {
		textArea.setBackground(Color.white);
		
	}
}