package com.heyang.common.gui.intro.area;

import java.io.File;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

import javax.swing.JLabel;

import org.dom4j.Document;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

import com.heyang.common.gui.intro.IntroComboBox;

/**
 * ʡ�����б��
 * 
 * @������ ����(heyang78@gmail.com)
 * 
 * @�汾��1.00
 * @�������� 2009-12-17
 * @����ʱ�� ����08:54:24
 */
@SuppressWarnings("unchecked")
public class ProvinceComboBox extends IntroComboBox {

    private static final long serialVersionUID = 1L;

    // ����ʡ����
    private static Set<String> provices = new LinkedHashSet<String>();;

    static {
        final String provinceXMLFile = "conf/const_province.xml";

        try {
            SAXReader reader = new SAXReader();
            File file = new File(provinceXMLFile);

            Document document = reader.read(file);
            Element rootElm = document.getRootElement();

            List<Element> elms = rootElm.elements();
            for (Element elm : elms) {
                String name = elm.getText();

                provices.add(name);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public ProvinceComboBox(String introduction) {
        super(introduction);
        this.refreshItems(provices);
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
    public ProvinceComboBox(String introduction, int horizontalAlignment) {
        super(introduction, horizontalAlignment);
        this.refreshItems(provices);
    }
}