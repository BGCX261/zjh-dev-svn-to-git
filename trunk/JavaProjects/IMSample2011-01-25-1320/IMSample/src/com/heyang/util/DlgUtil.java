package com.heyang.util;

import java.io.File;
import java.util.regex.Pattern;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;


/**
 * 文件过滤器类
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-16 下午11:29:45
 * 
 * 修改人：何杨
 * 修改时间：2010-2-16 下午11:29:45
 */
class FileFilter extends javax.swing.filechooser.FileFilter {
	// 扩展名
	String ext;
	
	public FileFilter(String strInExt){
		ext=strInExt;
	}
	
	/**
	 * �g���q�ł���t�@�C����Ԃ�
	 */
	public boolean accept(File file) {
		if(file.isDirectory()) return true;
		
		String filename = file.getName();		
		
		return filename.endsWith(ext);
	}
	
	/**
	 * �t�B���^�[�̐������擾����
	 */
	public String getDescription() {
		return ext+" file (*."+ext+")";
	}
}

/**
 * 对话框实用工具类
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-16 下午11:30:07
 * 
 * 修改人：何杨
 * 修改时间：2010-2-16 下午11:30:07
 */
public final class DlgUtil {
	/**
	 * <P>
	 * DialogBox 's title
	 * </P>
	 */
	private static String dialogTitle = "SqlToolBox";

	/**
	 * <P>
	 * Pointer of View
	 * </P>
	 */
	private static JFrame programFrame;

	/**
	 * 
	 * @param programFrame
	 */
	public static void setProgramFrame(JFrame programFrame) {
		DlgUtil.programFrame = programFrame;
	}


	/**
	 * 弹出一个确认对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:31:16
	 * 修改人：何杨 2010-2-16 下午11:31:16
	 */
	public static boolean popupConfirmDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		boolean retval = (boolean) (JOptionPane.showConfirmDialog(programFrame,
				promptWord, dialogTitle, JOptionPane.YES_NO_OPTION,
				JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION);
		return retval;
	}

	/**
	 * 弹出一个带取消按钮的确认对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:31:32
	 * 修改人：何杨 2010-2-16 下午11:31:32
	 */
	public static boolean popupConfirmCancelDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		boolean retval = (boolean) (JOptionPane.showConfirmDialog(programFrame,
				promptWord, dialogTitle, JOptionPane.YES_NO_CANCEL_OPTION,
				JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION);
		return retval;
	}

	/**
	 * 弹出一个消息提示框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * 创建人：何杨 2010-2-16 下午11:31:54
	 * 修改人：何杨 2010-2-16 下午11:31:54
	 */
	public static void popupMessageDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		JOptionPane.showMessageDialog(programFrame, promptWord, dialogTitle,
				JOptionPane.INFORMATION_MESSAGE);
	}

	/**
	 * 弹出一个错误消息对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * 创建人：何杨 2010-2-16 下午11:32:11
	 * 修改人：何杨 2010-2-16 下午11:32:11
	 */
	public static void popupErrorDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		JOptionPane.showMessageDialog(programFrame, promptWord, dialogTitle,
				JOptionPane.ERROR_MESSAGE);
	}

	/**
	 * 弹出一个警告对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * 创建人：何杨 2010-2-16 下午11:32:26
	 * 修改人：何杨 2010-2-16 下午11:32:26
	 */
	public static void popupWarningDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		JOptionPane.showMessageDialog(programFrame, promptWord, dialogTitle,
				JOptionPane.WARNING_MESSAGE);
	}

	/**
	 * 弹出一个问题对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * 创建人：何杨 2010-2-16 下午11:32:40
	 * 修改人：何杨 2010-2-16 下午11:32:40
	 */
	public static void popupQuestionDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		JOptionPane.showMessageDialog(programFrame, promptWord, dialogTitle,
				JOptionPane.QUESTION_MESSAGE);
	}

	/**
	 * 弹出一个输入框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param promptWord
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:28:21
	 * 修改人：何杨 2010-2-16 下午11:28:21
	 */
	public static String popupInputDialog(String promptWord) {
		promptWord=getFormattedMessage(promptWord);
		
		return JOptionPane.showInputDialog(programFrame, promptWord,
				dialogTitle, JOptionPane.OK_CANCEL_OPTION);
	}

	/**
	 * <P>
	 * last open folder
	 * </P>
	 */
	private static String lastOpenfile = "C:\\";

	/**
	 * 弹出一个打开文件对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param dialogTitle 对话框标题
	 * @param fileType 打开文件类型的扩展名
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:27:26
	 * 修改人：何杨 2010-2-16 下午11:27:26
	 */
	public static String openFileDialog(String dialogTitle, String fileType) {
		JFileChooser chooser = new JFileChooser();

		try {
			chooser.setCurrentDirectory(new File(new File(lastOpenfile)
					.getCanonicalPath()));
		} catch (Exception e) {
			e.printStackTrace();
		}

		chooser.setDialogTitle(dialogTitle);
		chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);

		chooser.addChoosableFileFilter(new FileFilter(fileType));
		String userSelectedFile = "";

		if (chooser.showOpenDialog(programFrame) == JFileChooser.APPROVE_OPTION) {
			userSelectedFile = chooser.getSelectedFile().getAbsolutePath();
			//lastOpenfile = userSelectedFile;
		}

		return userSelectedFile;
	}

	/**
	 * 弹出一个指定路径对话框,类似与SHFolder
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param dialogTitle 对话框标题
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:26:51
	 * 修改人：何杨 2010-2-16 下午11:26:51
	 */
	public static String openPathDialog(String dialogTitle) {
		JFileChooser chooser = new JFileChooser();
		chooser.setDialogTitle(dialogTitle);
		chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

		try {
			chooser.setCurrentDirectory(new File(new File(lastOpenfile)
					.getCanonicalPath()));
		} catch (Exception e) {
			e.printStackTrace();
		}

		String userSelectedFile = "";

		if (chooser.showOpenDialog(programFrame) == JFileChooser.APPROVE_OPTION) {
			userSelectedFile = chooser.getSelectedFile().getAbsolutePath();
			lastOpenfile = userSelectedFile;
		}

		return userSelectedFile;
	}
	
	/**
	 * 弹出保存文件对话框
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param dialogTitle 对话框的标题
	 * @param fileType 文件扩展名
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:25:38
	 * 修改人：何杨 2010-2-16 下午11:25:38
	 */
	public static String saveFileDialog(String dialogTitle, String fileType) {
		JFileChooser chooser = new JFileChooser();

		try {
			chooser.setCurrentDirectory(new File(new File(lastOpenfile)
					.getCanonicalPath()));
		} catch (Exception e) {
			e.printStackTrace();
		}

		chooser.setDialogTitle(dialogTitle);
		chooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

		chooser.addChoosableFileFilter(new FileFilter(fileType));
		String userSelectedFile = "";

		if (chooser.showSaveDialog(programFrame) == JFileChooser.APPROVE_OPTION) {
			userSelectedFile = chooser.getSelectedFile().getAbsolutePath();
			lastOpenfile = userSelectedFile;
		}

		return userSelectedFile;
	}

	/**
	 * 设置对话框标题
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param dialogTitle
	 * 创建人：何杨 2010-2-16 下午11:25:01
	 * 修改人：何杨 2010-2-16 下午11:25:01
	 */
	public static void setDialogTitle(String dialogTitle) {
		DlgUtil.dialogTitle = dialogTitle;
	}

	/**
	 * 取得程序的框架
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @return
	 * 创建人：何杨 2010-2-16 下午11:24:45
	 * 修改人：何杨 2010-2-16 下午11:24:45
	 */
	public static JFrame getProgramFrame() {
		return programFrame;
	}

	/**
	 * 这是为了让长文本换行在消息对话框上显示用的
	 * 
	 * @author：何杨
	 * @date：2009-12-28
	 * @time：上午08:50:58
	 * @param originalText
	 * @return
	 */
	private static  String getFormattedMessage(String originalText){
		// 每行固定宽度30,为十五个汉字或是三十个字母数字标点符号
		final int LetterCountInLine = 30;
		
		// 小于固定宽度时直接返回
		if(originalText.length()<=LetterCountInLine){
			return originalText;
		}
		
		// 现有字符数
		int letterCount=0;
		
		StringBuilder sb=new StringBuilder();
		
		for(int i=0;i<originalText.length()-1;i++){
			String c=originalText.substring(i, i+1);
			
			sb.append(c);
			
			letterCount+=getStringWidth(c);
			
			// 大于等于固定宽度时折行
			if(letterCount>=LetterCountInLine){
				sb.append("\r\n");
				letterCount=0;
			}
		}
		
		return sb.toString();
	}
	
	/**
	 * 得到单个字符的长度,非汉字为1,汉字为2
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param str
	 * @return
	 * 创建人：何杨 2010-2-17 上午12:09:31
	 * 修改人：何杨 2010-2-17 上午12:09:31
	 */
	private static int getStringWidth(String str){
		if(Pattern.matches("[\\u4E00-\\u9FA5]{1}",str)){
			return 2;
		}else{
			return 1;
		}
	}
}