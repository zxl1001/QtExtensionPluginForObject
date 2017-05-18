#include "smmanagerplugin.h"
#include "smmanagerpluginmodel.h"
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>
#include <QDebug>

namespace SMManager {

SMManagerPlugin::SMManagerPlugin() :
    ExtensionSystem::IPlugin()
{
}

bool SMManagerPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)
    qDebug()<<__FILE__<<__LINE__<<"SMManagerPlugin::initialize";
    QTranslator *translator = new QTranslator(this);
    translator->load(QLocale::system(), "smmanager", ".", ":/translations");
    qApp->installTranslator(translator);
    return true;
}

void SMManagerPlugin::extensionsInitialized()
{
    qDebug()<<__FILE__<<__LINE__<<"SMManagerPlugin::extensionsInitialized";
    SMManagerPluginModel *model = new SMManagerPluginModel;
    model->setPluginName("SMManagerPlugin");
    addAutoReleasedObject(model);
}

IPlugin::ShutdownFlag SMManagerPlugin::aboutToShutdown()
{
    return IPlugin::SynchronousShutdown;
}

}
/*-------------------------------------------
*  need to this code
---------------------------------------------*/
Q_EXPORT_PLUGIN(SMManagerPlugin)

