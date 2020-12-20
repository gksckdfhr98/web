package kr.or.connect.reservation.dto;

public class DisplayInfoImage {
	private String contentType;
	private String createDate;
	private boolean deleteFlag;
	private int displayInfoId;
	private int displayInfoImageId;
	private int fileId;
	private String fileName;
	private String modifyDate;
	private String saveFileName;
	public DisplayInfoImage() {
		super();
		// TODO Auto-generated constructor stub
	}
	public DisplayInfoImage(String contentType, String createDate, boolean deleteFlag, int displayInfoId,
			int displayInfoImageId, int fileId, String fileName, String modifyDate, String saveFileName) {
		super();
		this.contentType = contentType;
		this.createDate = createDate;
		this.deleteFlag = deleteFlag;
		this.displayInfoId = displayInfoId;
		this.displayInfoImageId = displayInfoImageId;
		this.fileId = fileId;
		this.fileName = fileName;
		this.modifyDate = modifyDate;
		this.saveFileName = saveFileName;
	}
	public String getContentType() {
		return contentType;
	}
	public void setContentType(String contentType) {
		this.contentType = contentType;
	}
	public String getCreateDate() {
		return createDate;
	}
	public void setCreateDate(String createDate) {
		this.createDate = createDate;
	}
	public boolean isDeleteFlag() {
		return deleteFlag;
	}
	public void setDeleteFlag(boolean deleteFlag) {
		this.deleteFlag = deleteFlag;
	}
	public int getDisplayInfoId() {
		return displayInfoId;
	}
	public void setDisplayInfoId(int displayInfoId) {
		this.displayInfoId = displayInfoId;
	}
	public int getDisplayInfoImageId() {
		return displayInfoImageId;
	}
	public void setDisplayInfoImageId(int displayInfoImageId) {
		this.displayInfoImageId = displayInfoImageId;
	}
	public int getFileId() {
		return fileId;
	}
	public void setFileId(int fileId) {
		this.fileId = fileId;
	}
	public String getFileName() {
		return fileName;
	}
	public void setFileName(String fileName) {
		this.fileName = fileName;
	}
	public String getModifyDate() {
		return modifyDate;
	}
	public void setModifyDate(String modifyDate) {
		this.modifyDate = modifyDate;
	}
	public String getSaveFileName() {
		return saveFileName;
	}
	public void setSaveFileName(String saveFileName) {
		this.saveFileName = saveFileName;
	}
	@Override
	public String toString() {
		return "DisplayInfoImage [contentType=" + contentType + ", createDate=" + createDate + ", deleteFlag="
				+ deleteFlag + ", displayInfoId=" + displayInfoId + ", displayInfoImageId=" + displayInfoImageId
				+ ", fileId=" + fileId + ", fileName=" + fileName + ", modifyDate=" + modifyDate + ", saveFileName="
				+ saveFileName + "]";
	}
	
	
}
