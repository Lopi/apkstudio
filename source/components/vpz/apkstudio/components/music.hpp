#ifndef VPZ_APKSTUDIO_COMPONENTS_MUSIC_HPP
#define VPZ_APKSTUDIO_COMPONENTS_MUSIC_HPP

#include <QAction>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QTreeWidget>
#include "async/copy.hpp"
#include "async/move.hpp"
#include "async/pull.hpp"
#include "async/remove.hpp"
#include "async/rename.hpp"
#include "helpers/adb.hpp"
#include "helpers/format.hpp"
#include "helpers/text.hpp"
#include "resources/embedded.hpp"
#include "resources/variant.hpp"
#include "tasks.hpp"

namespace VPZ {
namespace APKStudio {
namespace Components {

class Music : public QTreeWidget
{
    Q_OBJECT
private:
    QList<QMetaObject::Connection> connections;
    QString device;
private:
    static QString translate(const char *key) {
        return Helpers::Text::translate("music", key);
    }
private slots:
    void onCopy();
    void onCopyFinished(const QVariant &);
    void onDetails();
    void onMove();
    void onMoveFinished(const QVariant &, const QStringList &);
    void onPull();
    void onPullFinished(const QVariant &);
    void onRemove();
    void onRemoveFinished(const QVariant &, const QStringList &);
    void onRename();
    void onRenameFinished(const QVariant &, const QStringList &);
public:
    enum {
        ACTION_COPY = 1,
        ACTION_DETAILS,
        ACTION_MOVE,
        ACTION_PULL,
        ACTION_REMOVE,
        ACTION_RENAME
    };
    explicit Music(const QString &, QWidget * = 0);
    QVector<Resources::Music> selected();
    ~Music();
public slots:
    void onAction(QAction *);
    void onRefresh();
signals:
    void showFile(QString);
};

} // namespace Components
} // namespace APKStudio
} // namespace VPZ

#endif // VPZ_APKSTUDIO_COMPONENTS_MUSIC_HPP
