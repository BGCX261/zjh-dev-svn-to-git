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
 * �������ظ�ѡ��
 * 
 * @������ ����(heyang78@gmail.com)
 * 
 * @�汾��1.00
 * @�������� 2009-12-17
 * @����ʱ�� ����09:11:04
 */
@SuppressWarnings("unchecked")
public class CountyComboBox extends IntroComboBox {

    private static final long serialVersionUID = 4318137199354156303L;

    // ��(��)��ϣ��
    private static Map<String, List<String>> countyMap = new TreeMap<String, List<String>>();

    static {
        final String countyXMLFile = "conf/const_county.xml";

        try {
            SAXReader reader = new SAXReader();
            File file = new File(countyXMLFile);

            Document document = reader.read(file);

            XPath selector = DocumentHelper.createXPath("/datum/city");
            List ls = selector.selectNodes(document, selector);

            for (Iterator it = ls.iterator(); it.hasNext();) {
                Element cityElm = (Element) it.next();

                String cityName = "";

                List<String> countys = new ArrayList<String>();

                List countyElms = cityElm.elements();

                for (Iterator it2 = countyElms.iterator(); it2.hasNext();) {
                    Element countyElm = (Element) it2.next();

                    if (countyElm.getName().equals("name")) {
                        cityName = countyElm.getText();
                    } else {
                        countys.add(countyElm.getText());
                    }
                }

                countyMap.put(cityName, countys);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public CountyComboBox(String introduction) {
        super(introduction);
    }

    public void fillCounty(String city) {

        Set<String> set = new LinkedHashSet<String>();

        List<String> ls = countyMap.get(city);
        if (ls != null) {
            set.add("");
            for (String str : ls) {
                set.add(str);
            }
        }

        this.refreshItems(set);
    }
}