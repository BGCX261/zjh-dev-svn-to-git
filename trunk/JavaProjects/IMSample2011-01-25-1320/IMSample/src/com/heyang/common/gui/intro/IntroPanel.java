package com.heyang.common.gui.intro;

import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JPanel;

/**
 * �̳���IntroBase��,���������������Ǳ�ǩ
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:34
 */
public class IntroPanel extends IntroBase{
	private static final long serialVersionUID = -245353828300108L;
	

	/**
	 * IntroLabel���캯��
	 * @param introduction
	 */
	public IntroPanel(String introduction){
		// ���ø��๹�캯��
		super(introduction);
		
		component=new JPanel();
		component.setLayout(new BoxLayout(component,BoxLayout.LINE_AXIS));
	
		// ���ø������ò��ֲ����������ĺ���
		setLayoutAndAddComponents();
	}
	
	public void addToPanel(JComponent obj){
		component.add(obj);
	}
	
	public void removeAllObj(){
		component.removeAll();
	}
	
	/**
	 * ȡ��JTextField���û����������,��IntroBase��ǿ��ʵ�ֵĺ���
	 */
	public String getText(){
		return null;
	}
	
	/**
	 * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setFocus(){
		// do nothing
	}
	
	/**
	 * ����textField�е�����,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setText(String text){
		// do nothing
	}

}