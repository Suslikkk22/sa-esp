#include "plugin.h"
#include "game_sa/CFont.h"
#include "game_sa/CPools.h"
#include "game_sa/CWorld.h"
#include "game_sa/CSprite2d.h"
#include <string>
#include <stdio.h>

using namespace plugin;

class AmazingTreasureESP {
public:
    AmazingTreasureESP() {
        // Хукаемся в событие отрисовки игры
        Events::drawingEvent += [] {
            DrawTreasureInfo();
        };
    }

    static void DrawTreasureInfo() {
        // ID объекта клада на сервере (нужно будет уточнить, админы могут менять)
        // Допустим, это ящик или спец. модель. Замени 12345 на реальный ID.
        const int TREASURE_MODEL_ID = 12345; 
        
        bool found = false;
        CVector treasurePos = {0.0f, 0.0f, 0.0f};

        // Пробегаемся по пулу объектов в зоне стриминга
        CObjectPool* objPool = CPools::ms_pObjectPool;
        for (int i = 0; i < objPool->GetSize(); i++) {
            CObject* pObject = objPool->GetAt(i);
            if (pObject) {
                if (pObject->m_nModelIndex == TREASURE_MODEL_ID) {
                    treasurePos = pObject->GetPosition();
                    found = true;
                    break; // Нашли клад, выходим из цикла
                }
            }
        }

        // Если клад найден, рисуем текст снизу
        if (found) {
            char textBuffer[256];
            sprintf(textBuffer, "TREASURE DETECTED | X: %.2f Y: %.2f Z: %.2f", treasurePos.x, treasurePos.y, treasurePos.z);

            // Настройка шрифта GTA SA
            CFont::SetScale(0.4f, 0.6f);
            // Желтый цвет текста, чтобы хорошо было видно
            CFont::SetColor(CRGBA(255, 255, 0, 255)); 
            CFont::SetFontStyle(FONT_SUBTITLES);
            CFont::SetProportional(true);
            CFont::SetDropShadowPosition(1);
            CFont::SetDropColor(CRGBA(0, 0, 0, 255));
            CFont::SetAlignment(ALIGN_CENTER);

            // Рисуем текст внизу экрана (X: середина, Y: почти в самом низу)
            // Разрешение экрана берем динамически
            float screenX = RsGlobal.maximumWidth / 2.0f;
            float screenY = RsGlobal.maximumHeight - 50.0f; 

            CFont::PrintString(screenX, screenY, textBuffer);
        }
    }
} treasureEsp;
