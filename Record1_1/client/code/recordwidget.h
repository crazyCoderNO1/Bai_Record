#ifndef RECORDWIDGET_H
#define RECORDWIDGET_H
#include <QWidget>
#include <QFile>
#include <QPushButton>
#include <QAudioInput>
#include <QBuffer>


class RecordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RecordWidget(QWidget *parent = 0);
    ~RecordWidget();
signals:
    void RecordOk(QString fileName);        //录音结束发送该信号，通知netwidget自动发送音频文件
public slots:

private:
    void CreateInit();
    void CreateLaytout();

private:
    QPushButton *_startBtn,*_endBtn;//开始和结束按钮
    QAudioInput *_audioInput; //录音对象
    QFile outFile;
    QByteArray voiceData;
    QBuffer bufDevice;
};

#endif // RECORDWIDGET_H
