package com.heyang.common.gui.intro;

import java.awt.Color;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.text.JTextComponent;

/**
 * �̳���IntroBase��,���������������ǵ����ı���
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:34
 */
public class IntroText extends IntroBase  implements FocusListener {
	private static final long serialVersionUID = -2867677661828300108L;

	/**
	 * IntroText���캯��
	 * @param introduction
	 */
	public IntroText(String introduction){
		// ���ø��๹�캯��
		super(introduction);
		
		// ��componentʵ��ɵ����ı���,������ʵ�ֱ仯�Ĺؼ�����
		component=new JTextField();
		component.addFocusListener(this);
	
		// ���ø������ò��ֲ����������ĺ���
		setLayoutAndAddComponents();
	}

    /**
     * ֧��JTextField���Ҹ���һ����ǩ�Ĺ���
     * 
     * @author �½�
     * @date 2009-12-1
     * */
    public IntroText(String introduction, String unit) {
        // ���ø��๹�캯��
        super(introduction, unit);

        // ��componentʵ��ɵ����ı���,������ʵ�ֱ仯�Ĺؼ�����
        component = new JTextField();

        // ���ø������ò��ֲ����������ĺ���
        setLayoutAndAddComponents();
    }

    /**
     * �����������ֵ�ˮƽ���뷽ʽ
     * 
     * @author �½�
     * @date 2010-1-14
     * 
     * @see JLabel.LEFT
     * @see JLabel.RIGHT
     * @see JLabel.CENTER
     * */
    public IntroText(String introduction, int horizontalAlignment) {
        // ���ø��๹�캯��
        super(introduction, horizontalAlignment);

        // ��componentʵ��ɵ����ı���,������ʵ�ֱ仯�Ĺؼ�����
        component = new JTextField();

        // ���ø������ò��ֲ����������ĺ���
        setLayoutAndAddComponents();
    }

    /**
     * ֧��JComponent���Ҹ���һ����ǩ�Ĺ��ܲ������������ֵ�ˮƽ���뷽ʽ
     * 
     * @author �½�
     * @date 2010-1-15
     * 
     * @see JLabel.LEFT
     * @see JLabel.RIGHT
     * @see JLabel.CENTER
     * */
    public IntroText(String introduction, String unit, int horizontalAlignment) {
        // ���ø��๹�캯��
        super(introduction, unit, horizontalAlignment);

        // ��componentʵ��ɵ����ı���,������ʵ�ֱ仯�Ĺؼ�����
        component = new JTextField();

        // ���ø������ò��ֲ����������ĺ���
        setLayoutAndAddComponents();
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
		JTextField textField=(JTextField)component;
		
		return textField;
	}
	
	/**
	 * ȡ��JTextField���û����������,��IntroBase��ǿ��ʵ�ֵĺ���
	 */
	public String getText(){
		JTextField textField=(JTextField)component;
		
		return textField.getText();
	}
	
	/**
	 * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setFocus(){
		JTextField textField=(JTextField)component;
		textField.requestFocus();
	}
	
	/**
	 * ����textField�е�����,����IntroBaseǿ��ʵ�ֵĺ���
	 */
	public void setText(String text){
		JTextField textField=(JTextField)component;
		textField.setText(text);
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