package com.heyang.biz.client.chat.model;

import com.heyang.biz.client.userlist.model.UserlistModel;


/**
 * Chat Window's Datum Center
 * @author heyang
 *
 */
public class ChatModel{
	// Other site in the chat
	private String opponentName;
	
	// 用户列表窗口的数据中心的引用
	private UserlistModel userListModel;
	
	/**
	 * 在父窗口中删除数据
	 */
	public void removeMydataInUserlistWondow(){
		userListModel.removeChatWindow(opponentName);
	}

	public String getOpponentName() {
		return opponentName;
	}

	public void setOpponentName(String opponentName) {
		this.opponentName = opponentName;
	}

	public UserlistModel getUserListModel() {
		return userListModel;
	}

	public void setUserListModel(UserlistModel userListModel) {
		this.userListModel = userListModel;
	}
}