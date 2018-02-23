﻿#ifndef SATABLEVIEW_H
#define SATABLEVIEW_H
#include "SACommonUIGlobal.h"
#include <QTableView>
class QKeyEvent;
///
/// \brief SA 数据表格的封装
/// - 添加全局剪切板复制功能
/// - 添加全局剪切板粘贴功能
/// - 添加ctrl+滚轮缩放功能
///
///
class SA_COMMON_UI_EXPORT SATableView : public QTableView
{
    Q_OBJECT
public:
    SATableView(QWidget* par = Q_NULLPTR);
protected:
    void keyPressEvent(QKeyEvent *e);
    //处理ctrl+c事件
    virtual void onCtrlCPressed();
    //处理ctrl+v事件
    virtual void onCtrlVPressed();
private:
    static QSize getSelectSize(const QModelIndexList& indexs, int* minRow, int* maxRow, int *minCol, int *maxCol);
    static QString toTabString(QString **tableString, const int r, const int c);
};

#endif // SADATATABLEVIEW_H
