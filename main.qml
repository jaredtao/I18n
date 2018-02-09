import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    ComboBox {
        model: [
            "en",
            "zh"
        ]
        onCurrentTextChanged: {
            i18n.reTrans(currentText);
        }
    }
    Text {
        anchors.centerIn: parent
        text: qsTr("HaHa")
    }
}
