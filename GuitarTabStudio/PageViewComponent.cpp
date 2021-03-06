#include "stdafx.h"
#include "PageViewComponent.h"


PageViewComponent::PageViewComponent(ViewInfo* viewInfo, UCHAR num) : ViewComponent(viewInfo, NULL, NULL) {
	this->num = num;
	this->resize(viewInfo->viewConfiguration->getPageWidth(viewInfo->scale), 
		viewInfo->viewConfiguration->getPageHeight(viewInfo->scale));
}


PageViewComponent::~PageViewComponent() {
}

TactContainerViewComponent * PageViewComponent::getTactContainer() {
	return this->tactContainer;
}

void PageViewComponent::selfDraw(HDC hdc) {
	FillRectangle(hdc, this->getX(), this->getY(), this->getWidth(), this->getHeight(),
		this->viewInfo->viewConfiguration->getSolidBrush(this->viewInfo->mainBackgroundColor));
	SHORT height = this->viewInfo->viewConfiguration->getPageNumFontHeight(this->viewInfo->scale);
	SHORT width = height * 4;
	HFONT font = this->viewInfo->viewConfiguration->getFont(height);
	wstring text = to_wstring(this->num);
	RECT rect;
	rect.left = this->getX() + this->getWidth() - width;
	rect.top = this->getY() + this->getHeight() - height;
	rect.bottom = this->getY() + this->getHeight();
	rect.right = this->getX() + this->getWidth();
	HANDLE oldFont = SelectObject(hdc, font);
	DrawText(hdc, text.c_str(), text.size(), &rect, DT_CENTER);
	SelectObject(hdc, oldFont);
}
