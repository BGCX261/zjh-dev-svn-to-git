package com.heyang.common.gui.intro.area;

import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.XPath;
import org.dom4j.io.SAXReader;

import com.heyang.common.gui.intro.IntroComboBox;

/**
 * �����и�ѡ��
 * 
 * @������ ����(heyang78@gmail.com)
 * 
 * @�汾��1.00
 * @�������� 2009-12-17
 * @����ʱ�� ����09:03:31
 */
@SuppressWarnings("unchecked")
public class CityComboBox extends IntroComboBox {

    private static final long serialVersionUID = -4258152554493024534L;

    // �����й�ϣ��
    private static Map<String, List<String>> cityMap = new TreeMap<String, List<String>>();

    static {
        final String cityXMLFile = "conf/const_city.xml";

        try {
            SAXReader reader = new SAXReader();
            File file = new File(cityXMLFile);

            Document document = reader.read(file);

            XPath selector = DocumentHelper.createXPath("/datum/province");
            List ls = selector.selectNodes(document, selector);

            for (Iterator it = ls.iterator(); it.hasNext();) {
                Element provinceElm = (Element) it.next();

                String provinceName = provinceElm.attributeValue("name");

                List<String> citys = new ArrayList<String>();

                List cityElms = provinceElm.elements();

                for (Iterator it2 = cityElms.iterator(); it2.hasNext();) {
                    Element cityElm = (Element) it2.next();

                    citys.add(cityElm.getText());
                }

                cityMap.put(provinceName, citys);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public CityComboBox(String introduction) {
        super(introduction);
    }

    public void fillCity(String province) {
        Set<String> set = new LinkedHashSet<String>();

        List<String> ls = cityMap.get(province);
        if (ls != null) {
            set.add("");
            for (String str : ls) {
                set.add(str);
            }
        }

        this.refreshItems(set);
    }
}