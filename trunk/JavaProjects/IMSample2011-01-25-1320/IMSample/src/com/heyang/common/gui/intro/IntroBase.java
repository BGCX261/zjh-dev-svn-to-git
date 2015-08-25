package com.heyang.common.gui.intro;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;

import org.apache.commons.lang.StringUtils;




/**
 * �����ֽ��ܵ�������,��IntroText,IntroArea,IntroCombo�Ļ���
 * 
 * @author ����
 * @date 2009-10-12
 * @time ����09:11:25
 */
public abstract class IntroBase extends JPanel {

    private static final long serialVersionUID = 7605966001362344872L;

    // ��λ��ǩ�����������Ҳ� add by �½� 2009-12-1
    protected JLabel unitLabel;

    // ���ֽ��ܱ�ǩ,������඼Ҫʹ��,�ʶ���ɵ�����
    protected JLabel introLbl;

    // Textfield,TextArea,Combo�Ļ���,����ָ������ӿؼ�
    protected JComponent component;

    public IntroBase(String introduction) {
        introLbl = new JLabel(" " + introduction + " ");
        introLbl.setForeground(Color.black);
        introLbl.setVerticalAlignment(JLabel.CENTER);
        introLbl.setHorizontalAlignment(JLabel.RIGHT);
    }

    /**
     * ֧��JComponent���Ҹ���һ����ǩ�Ĺ���
     * 
     * @author �½�
     * @date 2009-12-1
     * */
    public IntroBase(String introduction, String unit) {
        introLbl = new JLabel(" " + introduction + " ");
        introLbl.setVerticalAlignment(JLabel.CENTER);
        introLbl.setHorizontalAlignment(JLabel.RIGHT);

        unitLabel = new JLabel(" " + unit + " ");
        unitLabel.setVerticalAlignment(JLabel.CENTER);
        unitLabel.setHorizontalAlignment(JLabel.LEFT);
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
    public IntroBase(String introduction, int horizontalAlignment) {
        introLbl = new JLabel(introduction);
        introLbl.setVerticalAlignment(JLabel.CENTER);
        introLbl.setHorizontalAlignment(horizontalAlignment);
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
    public IntroBase(String introduction, String unit, int horizontalAlignment) {
        introLbl = new JLabel(introduction);
        introLbl.setVerticalAlignment(JLabel.CENTER);
        introLbl.setHorizontalAlignment(horizontalAlignment);

        unitLabel = new JLabel(" " + unit + " ");
        unitLabel.setVerticalAlignment(JLabel.CENTER);
        unitLabel.setHorizontalAlignment(JLabel.LEFT);
    }

    /**
     * ���ò��ֲ���ʼ������������벼��,�ڵ�����֮ǰӦ�ð�componentʵ��
     */
    protected void setLayoutAndAddComponents() {
        // �趨����ΪGridBagLayout���ֲ����������ĸ������
        int gridx, gridy, gridwidth, gridheight, anchor, fill, ipadx, ipady;
        double weightx, weighty;
        GridBagConstraints c;
        Insets inset;
        GridBagLayout gridbag = new GridBagLayout();
        setLayout(gridbag);

        gridx = 0;// 1
        gridy = 0;// 1
        gridwidth = 1;
        gridheight = 1;
        weightx = 0.00;// 2
        weighty = 1.00;// 2
        anchor = GridBagConstraints.CENTER;
        fill = GridBagConstraints.BOTH;
        inset = new Insets(0, 0, 0, 0);
        ipadx = 0;
        ipady = 0;
        c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
                weightx, weighty, anchor, fill, inset, ipadx, ipady);
        gridbag.setConstraints(introLbl, c);// 3
        add(introLbl);// 3
        Dimension labelDimension = new Dimension(80, 20);
        introLbl.setMaximumSize(labelDimension);
        introLbl.setMinimumSize(labelDimension);
        introLbl.setPreferredSize(labelDimension);

        gridx = 1;
        gridy = 0;
        gridwidth = 1;
        gridheight = 1;
        weightx = 1.00;
        weighty = 1.00;
        anchor = GridBagConstraints.WEST;
        fill = GridBagConstraints.BOTH;
        inset = new Insets(0, 0, 0, 0);
        ipadx = 0;
        ipady = 0;
        c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
                weightx, weighty, anchor, fill, inset, ipadx, ipady);
        gridbag.setConstraints(component, c);
        add(component);
        // Dimension labelDimension = new Dimension(130, 20);
        component.setMaximumSize(new Dimension(1300, 25));
        component.setMinimumSize(new Dimension(1, 25));
        component.setPreferredSize(new Dimension(130, 25));

        // ��"unitLabel"���������Ҳ� add by �½� 2009-12-1
        if (unitLabel != null && StringUtils.isNotBlank(unitLabel.getText())) {
            gridx = 2;
            gridy = 0;
            gridwidth = 1;
            gridheight = 1;
            weightx = 0.00;
            weighty = 1.00;
            anchor = GridBagConstraints.WEST;
            fill = GridBagConstraints.BOTH;
            inset = new Insets(0, 0, 0, 0);
            ipadx = 0;
            ipady = 0;
            c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
                    weightx, weighty, anchor, fill, inset, ipadx, ipady);
            gridbag.setConstraints(unitLabel, c);
            add(unitLabel);
            // labelDimension = new Dimension(80, 20);
            // unitLabel.setMaximumSize(labelDimension);
            // unitLabel.setMinimumSize(labelDimension);
            // unitLabel.setPreferredSize(labelDimension);
        }
    }

    /**
     * ȡ���û������ѡ�������,ǿ������ʵ��
     * 
     * @return
     */
    public abstract String getText();

    /**
     * �������������,ǿ������ʵ��
     * 
     * @return
     */
    public abstract void setText(String text);

    /**
     * ������ؼ��������뽹��,ǿ������ʵ��
     * 
     */
    public abstract void setFocus();

    public void setColors(Color bgColor, Color leftForeColor,
            Color rightForeColor) {
        this.setBackground(bgColor);
        introLbl.setForeground(leftForeColor);

        // JLabel ctrl=(JLabel)component;
        component.setForeground(rightForeColor);
    }

    public void setRightForeColor(Color rightForeColor) {
        // JLabel ctrl=(JLabel)component;
        component.setForeground(rightForeColor);
    }

    public void setRightBackgroundColor(Color rightForeColor) {
        // JLabel ctrl=(JLabel)component;
        component.setBackground(rightForeColor);
    }

    public void setLeftDemension(Dimension dm) {
        introLbl.setMaximumSize(dm);
        introLbl.setMinimumSize(dm);
        introLbl.setPreferredSize(dm);
    }

    public void setRightDemension(Dimension dm) {
        // JLabel ctrl=(JLabel)component;

        component.setMaximumSize(dm);
        component.setMinimumSize(dm);
        component.setPreferredSize(dm);
    }

    public JComponent getRightComponent() {
        return component;
    }

    /**
     * ����"���ֽ��ܱ�ǩ"
     * 
     * @author �½�
     * @date 2009-11-30
     * */
    public JLabel getLabel() {
        return introLbl;
    }
    
    /**
     * ���ر�ǩ����
     * 
     * @author������
     * @date��2009-12-17
     * @time������10:19:40
     * @return
     */
    public String getLabelText() {
        return introLbl.getText();
    }
    
    /**
     * ���ñ�ǩ�Ĵ�С�������������Ҫ�?����ʱʹ��
     * 
     * @author������
     * @date��2009-12-22
     * @time������09:36:48
     * @param dm
     */
    public void setLabelSize(Dimension dm){
    	introLbl.setSize(dm);
    	introLbl.setMaximumSize(dm);
    	introLbl.setMinimumSize(dm);
    	introLbl.setPreferredSize(dm);
    }
    
    /**
     * �����ұ�����Ĵ�С����������ڿ����ұ�������ʱʹ��
     * 
     * @author������
     * @date��2009-12-22
     * @time������09:40:07
     * @param dm
     */
    public void setRighterSize(Dimension dm){
    	component.setSize(dm);
    	component.setMaximumSize(dm);
    	component.setMinimumSize(dm);
    	component.setPreferredSize(dm);
    }
}