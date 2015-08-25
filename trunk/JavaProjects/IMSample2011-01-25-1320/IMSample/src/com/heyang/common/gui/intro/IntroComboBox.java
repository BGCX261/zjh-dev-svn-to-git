package com.heyang.common.gui.intro;

import java.awt.Dimension;
import java.util.Collection;

import javax.swing.JComboBox;
import javax.swing.JLabel;

/**
 * �̳���IntroBase��,���������������Ǹ��Ͽ�
 * 
 * @author ����
 * 
 * @date:2009-11-3
 * @time:����03:06:19
 */
public class IntroComboBox extends IntroBase {

    private static final long serialVersionUID = -2867677661828300108L;

    /**
     * IntroCombo���캯��
     * 
     * @param introduction
     */
    public IntroComboBox(String introduction) {
        // ���ø��๹�캯��
        super(introduction);

        // ��componentʵ��ɸ��Ͽ�,������ʵ�ֱ仯�Ĺؼ�����
        component = new JComboBox();

        // ���ø������ò��ֲ����������ĺ���
        setLayoutAndAddComponents();

    }

    /**
     * ֧��JComboBox���Ҹ���һ����ǩ�Ĺ���
     * 
     * @author �½�
     * @date 2009-12-1
     * */
    public IntroComboBox(String introduction, String unit) {
        // ���ø��๹�캯��
        super(introduction, unit);

        // ��componentʵ��ɸ��Ͽ�,������ʵ�ֱ仯�Ĺؼ�����
        component = new JComboBox();

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
    public IntroComboBox(String introduction, String unit, int horizontalAlignment) {
        // ���ø��๹�캯��
        super(introduction, unit, horizontalAlignment);

        // ��componentʵ��ɸ��Ͽ�,������ʵ�ֱ仯�Ĺؼ�����
        component = new JComboBox();

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
    public IntroComboBox(String introduction, int horizontalAlignment) {
        // ���ø��๹�캯��
        super(introduction, horizontalAlignment);

        // ��componentʵ��ɸ��Ͽ�,������ʵ�ֱ仯�Ĺؼ�����
        component = new JComboBox();

        // ���ø������ò��ֲ����������ĺ���
        setLayoutAndAddComponents();
    }

    /**
     * ȡ�ø��Ͽ����û�ѡ�������,��IntroBase��ǿ��ʵ�ֵĺ���
     */
    public String getInputText() {
        JComboBox combo = (JComboBox) component;

        return combo.getSelectedItem().toString();
    }

    /**
     * ������ؼ����ý���,,����IntroBaseǿ��ʵ�ֵĺ���
     */
    public void setFocus() {
        JComboBox combo = (JComboBox) component;
        combo.requestFocus();
    }

    /**
     * ����combo�е�����,����IntroBaseǿ��ʵ�ֵĺ���
     */
    public void setText(String text) {
        JComboBox combo = (JComboBox) component;

        int num = combo.getItemCount();
        for (int i = 0; i < num; i++) {
            String itemText = combo.getItemAt(i).toString();

            if (itemText.equals(text)) {
                combo.setSelectedIndex(i);
                return;
            }
        }
    }

    /**
     * ���ַ������뵽combo��,����IntroBaseǿ��ʵ�ֵĺ���
     */
    public void insertText(String text) {
        JComboBox combo = (JComboBox) component;

        combo.setSelectedItem(text);
    }

    /*
     * public void refreshItems(List<String> items){ JComboBox
     * combo=(JComboBox)component; combo.removeAllItems();
     * 
     * for(String item:items){ combo.addItem(item); } }
     */
    /**
     * ���¸��Ͽ��е�ѡ��
     * 
     */
    public void refreshItems(Collection<String> items) {
        JComboBox combo = (JComboBox) component;
        combo.removeAllItems();

        for (String item : items) {
            combo.addItem(item);
        }
    }

    /**
     * ��Ӹ��Ͽ��е�ѡ��
     * 
     * @date��2009-11-19
     * @time������01:36:57
     * @param items
     */
    public void addItems(Collection<String> items) {
        JComboBox combo = (JComboBox) component;

        for (String item : items) {
            combo.addItem(item);
        }
    }

    @Override
    public String getText() {
        JComboBox combo = (JComboBox) component;
        return combo.getSelectedItem() == null ? "" : combo.getSelectedItem()
                .toString();
    }

    public JComboBox getComboBox() {
        JComboBox combo = (JComboBox) component;
        return combo;
    }

    public void addItem(Object item) {
        JComboBox combo = (JComboBox) component;
        combo.addItem(item);
    }

    public Object getSelectedItem() {
        JComboBox combo = (JComboBox) component;
        return combo.getSelectedItem();
    }

    public void removeAllItems() {
        JComboBox combo = (JComboBox) component;
        combo.removeAllItems();
    }

    public void setSelectedIndex(int i) {
        JComboBox combo = (JComboBox) component;
        combo.setSelectedIndex(i);
    }

    public void setLabelSize(Dimension dimension) {
        introLbl.setMinimumSize(dimension);
        introLbl.setMaximumSize(dimension);
        introLbl.setPreferredSize(dimension);
        introLbl.setSize(dimension);
    }

    public void setRighterSize(Dimension dimension) {
        JComboBox combo = (JComboBox) component;
        combo.setMinimumSize(dimension);
        combo.setMaximumSize(dimension);
        combo.setPreferredSize(dimension);
        combo.setSize(dimension);
    }
}