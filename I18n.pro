QT += quick
CONFIG += c++11

SOURCES += \
    main.cpp

RESOURCES += qml.qrc

HEADERS += \
    I18n.hpp

TRANSLATIONS += I18n_zh.ts \
        I18n_en.ts

#  自动生成qm文件到运行路径
qtPrepareTool(LRELEASE, lrelease)
for(tsfile, TRANSLATIONS) {
    qmfile = $$shadowed($$tsfile)
    qmfile ~= s,.ts$,.qm,
    qmdir = $$dirname(qmfile)
    !exists($$qmdir) {
        mkpath($$qmdir)|error("Aborting.")
    }
    command = $$LRELEASE -removeidentical $$tsfile -qm $$qmfile
    system($$command)|error("Failed to run: $$command")
    TRANSLATIONS_FILES += $$qmfile
}
