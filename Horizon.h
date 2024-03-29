#pragma once

#include <QMainWindow>
#include "ui_Horizon.h"
#include "SmartEdit.h"
#include "newFileDialog.h"
#include "readinDialog.h"
#include "Parser/MyParser.h"

namespace Ui {
	class Horizon;
}

struct Var
{
	QString Line = NULL;
	QString Type = NULL;
	QString Name = NULL;
	QString Val = NULL;
	QString Msg = NULL;
};
class Horizon : public QMainWindow{
	Q_OBJECT

public:
	Horizon(QMainWindow *parent = Q_NULLPTR);
	~Horizon(); 
	QLabel* curDateTimeWidget;
	QTimer* timer;
	bool tabNotEmpty();
	QString fTest();

public slots:
	void showCurDateTime();
	void tab_Synto_List(int index);
	void fUndo();
	void fRedo();
	void fCut();
	void fCopy();
	void fPaste();
	void fSelectAll();
	void fAbout();
	bool lineInvalid(QString curText);

protected:
	void closeEvent(QCloseEvent* event)override;

private:
	Ui::HorizonClass horizonUi;
	QSplitter* horizontalSplitter; //水平分割器，垂直向
	QSplitter* verticalSplitter;//垂直分割器，水平向
	QListWidget* listWidget;//列表，展示文件
	QList<SmartEdit*>* editors;//已打开的编辑框
	QStringList file_names;//已打开的文件
	QStringList file_paths;//对应路径
	QTabWidget* inputTab;//切换图，展示编辑框
	QTabWidget* outputTab;
	QTextEdit* consoleView; //控制框，静态语义分析结果
	QTextEdit* IEView;//解释执行框，中间变量值
	MyParser* parser;
	QList<Var*>* vars;

	const char* SLR1Txt = ".//res//tools//SLR1.txt"
		, * MyProductions = ".//res//tools//MyProductions.txt";
	const QString productPath = ".//res//product//";

	QList<Var*>* ReadVal(QString out);
	int FindFirstPoint(QList<Var*>* vars, QList<int> points);
	int Step(QList<Var*>* vars);


private slots:
	int fQuit();
	int fSave();
	void fNew();
	void fOpen();
	void fSave_All();
	void fClose();
	void fSafeRun();
	void fCancelDebug();
	void fStaticSemanticAnalysis();
	void fBreak();
	void fCancelBreak();
	void fLineDebug();
	void fPointDebug();
};
