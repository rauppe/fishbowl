#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QLayout>
#include <QObject>
#include <QVector>
#include <vector>

#include "../profiles/fish.h"
#include "../profiles/profile.h"
#include "../groups/group.h"
#include "QtWidgets/qlistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_homeButton_clicked();

    void on_groupButton_clicked();

    void on_messageButton_clicked();

    void on_friendsButton_clicked();

    void on_profileButton_clicked();

    void on_fishButton_clicked();

    void on_toolButton_clicked();

    void on_finished_accepted();

    void addFish(QString, QString, QString);

    void on_fishlist_itemDoubleClicked(QListWidgetItem *item);

    void on_finished_rejected();

    void on_EditFishProfile_clicked();

    void on_edit_accepted();

    void on_friends_clicked();

    void on_groups_clicked();

    void on_posts_clicked();

    void on_fish_clicked();

private:
    Ui::Home *ui;
    profile p;
    fish* f;
};
#endif // HOME_H
