package com.heyang.biz.server.view;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.text.Format;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.AbstractAction;
import javax.swing.JTextPane;
import javax.swing.KeyStroke;
import javax.swing.event.UndoableEditEvent;
import javax.swing.event.UndoableEditListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.JTextComponent;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.text.TextAction;
import javax.swing.undo.CannotRedoException;
import javax.swing.undo.CannotUndoException;
import javax.swing.undo.UndoManager;

import com.heyang.util.DlgUtil;

/**
 * 用户输入Sql及其它文本用的文本窗格
 * 说明：
 * 作者：heyang(heyang78@gmail.com)
 * 创建时间：2010-5-2 上午11:45:09
 * 修改时间：2010-5-2 上午11:45:09
 */
public class InputTextPane extends JTextPane{
	private static final long serialVersionUID = -3120527751030350540L;
	
	// 三种颜色的字体风格
	public static final String RED_STYLE = "RedStyle";// 用于显示错误信息
	public static final String BLACK_STYLE = "BlackStyle";// 用于显示正常文本
	public static final String BLUE_STYLE = "BlueStyle";// 用于显示高亮文本
	
	// 操作文本用的文档对象
	protected StyledDocument doc;
	
	// Undo管理器
	private UndoManager undo ;
	
	/**
	 * 构造函数
	 */
	public InputTextPane(){
		super();
		doc=(StyledDocument)this.getDocument();
		initialStyles();
		
		/*if(doc instanceof AbstractDocument){
			AbstractDocument adoc=(AbstractDocument)doc;
			
			adoc.setDocumentFilter(new HighLightFilter(this));
		}*/
		
		undo = new UndoManager();
		doc.addUndoableEditListener(new UndoableEditListener() {
			public void undoableEditHappened(UndoableEditEvent e) {
				undo.addEdit(e.getEdit());
			}
		});
		
		// 添加Undo，Redo，Shift+Tab的处理
		//addActionMap();
	}
	
	/**
	 * 初始化各种字体风格
	 * 
	 * 说明：
	 * 创建时间：2010-5-2 上午11:50:17
	 * 修改时间：2010-5-2 上午11:50:17
	 */
	private void initialStyles(){
		Style BlueStyle = doc.addStyle(BLUE_STYLE, null);
        StyleConstants.setForeground(BlueStyle, Color.blue);
        
        Style BlackStyle = doc.addStyle(BLACK_STYLE, null);
        StyleConstants.setForeground(BlackStyle, Color.black);
        
        Style RedStyle = doc.addStyle(RED_STYLE, null);
        StyleConstants.setForeground(RedStyle, Color.red);
	}
	
	/**
	 * 在头部添加黑色信息以显示送给客户端的resposne
	 * 
	 * 说明：
	 * @param msg
	 * 创建时间：2010-5-2 上午11:49:17
	 * 修改时间：2010-5-2 上午11:49:17
	 */
	public void insertBlackMsg(String msg,String remoteIp){
		try{
			String text=getCurrTime()+"(Response to "+remoteIp+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(BLACK_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	/**
	 * 插入发送的消息
	 * 
	 * 说明：
	 * @param msg
	 * @param toUser
	 * 创建时间：2010-12-30 下午11:47:38
	 */
	public void insertSendMsg(String msg,String toUser){
		try{
			String text=getCurrTime()+"(Send message to "+toUser+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(BLACK_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	/**
	 * 在头部添加红色文本以显示错误信息
	 * 
	 * 说明：
	 * @param msg
	 * 创建时间：2010-5-3 下午01:45:04
	 * 修改时间：2010-5-3 下午01:45:04
	 */
	public void insertRedMsg(String msg,String remoteIp){
		try{
			String text=getCurrTime()+"(Error of "+remoteIp+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(RED_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	public void insertDispatchMsg(String msg,String remoteIp){
		try{
			String text=getCurrTime()+"(Dispatched by "+remoteIp+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(RED_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	/**
	 * 在头部添加蓝色信息以显示客户端送来的request
	 * 
	 * 说明：
	 * @param msg
	 * 创建时间：2010-12-28 上午11:54:37
	 */
	public void insertBlueMsg(String msg,String remoteIp){
		try{
			String text=getCurrTime()+"(Request from "+remoteIp+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(BLUE_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	/**
	 * 
	 * 插入收到的消息
	 * 说明：
	 * @param msg
	 * @param fromUser
	 * 创建时间：2010-12-30 下午11:49:22
	 */
	public void insertReceivedMsg(String msg,String fromUser){
		try{
			String text=getCurrTime()+"(Receive message from "+fromUser+")\n"+msg+"\n\n";
			doc.insertString(0, text, doc.getStyle(BLUE_STYLE));
		}
		catch(Exception ex){
			DlgUtil.popupWarningDialog("不能将文本插入文本窗格的起始位置");
			ex.printStackTrace();
		}
	}
	
	/**
	 * 取得当前日期时间
	 */
	private static String getCurrTime() {
		Date date = new Date();
		Format formatter = new SimpleDateFormat("HH:mm:ss>");
		return formatter.format(date);
	}
	
	/**
	 * 添加Undo，Redo，Shift+Tab的处理
	 * 
	 * 说明：
	 * 创建时间：2010-5-6 上午11:37:38
	 * 修改时间：2010-5-6 上午11:37:38
	 */
	public void addActionMap() {
		/**
		 * Undo的处理
		 */
		String undoText="Undo";
		getActionMap().put(undoText, new AbstractAction(undoText) {
			private static final long serialVersionUID = -5768831351483901728L;

			public void actionPerformed(ActionEvent evt) {
				try {
					if (undo.canUndo()) {
						undo.undo();
					}
				} catch (CannotUndoException e) {
				}
			}
		});
		getInputMap().put(KeyStroke.getKeyStroke("control Z"), undoText);
		
		
		/**
		 * Redo的处理
		 */
		String redoText="Redo";
		getActionMap().put(redoText, new AbstractAction(redoText) {
			private static final long serialVersionUID = -6920959884440395654L;

			public void actionPerformed(ActionEvent evt) {
				try {
					if (undo.canRedo()) {
						undo.redo();
					}
				} catch (CannotRedoException e) {
				}
			}
		});
		getInputMap().put(KeyStroke.getKeyStroke("control R"), redoText);
		
		
		// 2009年1月23日8:12:13
		// 缩退处理
	    String tabText = "Tab";
	    getInputMap().put(KeyStroke.getKeyStroke(KeyEvent.VK_TAB,0), tabText);
	    
	    // 设置缩退处理的动作
	    getActionMap().put(tabText,
	        new TextAction(tabText) {	    	
	    		private static final long serialVersionUID = -66324231604787553L;
	    	
	            public void actionPerformed(ActionEvent evt) {
	                tabSelection(getTextComponent(evt));
	            }
	        }
	    );
	    
		// 2009年1月23日8:29:41
		// 缩进处理
	    String shiftTabText = "ShiftTab";
	    // 下面的1表示Shift键按下
	    getInputMap().put(KeyStroke.getKeyStroke(KeyEvent.VK_TAB,1), shiftTabText);
	    
	    // 设置缩进处理的动作
	    getActionMap().put(shiftTabText,
	        new TextAction(shiftTabText) {	    	
	    		private static final long serialVersionUID = 43544531604787553L;
	    	
	            public void actionPerformed(ActionEvent evt) {
	                shiftTabSelection(getTextComponent(evt));
	            }
	        }
	    );
	}
	
	/**
	 * 当按下Tab键时使文本缩进
	 * 2009年1月23日8:29:12
	 * @param comp
	 */
	private void shiftTabSelection(JTextComponent comp) {
        if (comp.getSelectionStart() < comp.getSelectionEnd()) {
        	// 使文本缩进
        	
        	// 选择文本的位置
            int s = comp.getSelectionStart();
            int e = comp.getSelectionEnd();
            
            // 选择的文本
            String text=comp.getSelectedText();
            
            // 对选择文本的加工处理
            String[] arr=text.split("(\r\n)|(\n)");
            
            StringBuffer sb=new StringBuffer();
            for(String line:arr){
            	String shiftTabedLine=line;
            	if(line.startsWith("    ")){
            		shiftTabedLine=line.substring(4);
            	}
            	
            	sb.append(shiftTabedLine+"\n");
            }  
            
            // 加工完（缩退完毕）的文本
            String tabedText=sb.toString();
            
            // 替换原有文本
            comp.replaceSelection(tabedText);
            
            // 重新选择缩退后的文本
            e=s+tabedText.length();
            comp.select(s, e);
        }
    }
	
	/**
	 * 当按下Tab键时使文本缩退
	 * 2009年1月23日8:29:12
	 * @param comp
	 */
	private void tabSelection(JTextComponent comp) {
        if (comp.getSelectionStart() == comp.getSelectionEnd()) {
            // There is no selection, only a caret
            if (comp.getCaretPosition() < comp.getDocument().getLength()) {
                // The caret must be at least one position left of the end
                try {
                    int pos = comp.getCaretPosition();
                    Document doc = comp.getDocument();
                    String str = doc.getText(pos, 1).toLowerCase();
    
                    doc.remove(pos, 1);
                    doc.insertString(pos, str, null);
                    comp.moveCaretPosition(pos+1);
                } catch (BadLocationException e) {
                }
            }
        } else {
        	// 使文本缩退
        	
        	// 选择文本的位置
            int s = comp.getSelectionStart();
            int e = comp.getSelectionEnd();
            
            // 选择的文本
            String text=comp.getSelectedText();
            
            // 对选择文本的加工处理
            String[] arr=text.split("(\r\n)|(\n)");
            
            StringBuffer sb=new StringBuffer();
            for(String line:arr){
            	sb.append("    "+line+"\n");
            }  
            
            // 加工完（缩退完毕）的文本
            String tabedText=sb.toString(); 
            
            // 替换原有文本
            comp.replaceSelection(sb.toString());
            
            // 重新选择缩退后的文本
            e=s+tabedText.length();
            comp.select(s, e);
        }
    }
	
	/**
	 * 恢复上一步操作
	 * 
	 * 说明：
	 * 创建时间：2010-5-6 上午11:48:58
	 * 修改时间：2010-5-6 上午11:48:58
	 */
	public void undo(){
		try {
			if (undo.canUndo()) {
				undo.undo();
			}
		} catch (CannotUndoException e) {
		}
	}
	
	/**
	 * 再次执行上一步操作
	 * 
	 * 说明：
	 * 创建时间：2010-5-6 上午11:49:16
	 * 修改时间：2010-5-6 上午11:49:16
	 */
	public void redo(){
		try {
			if (undo.canRedo()) {
				undo.redo();
			}
		} catch (CannotRedoException e) {
		}
	}
}