#include "plugin.h"
#include "game_sa/CFont.h"
#include "game_sa/CPools.h"
#include "game_sa/CWorld.h"
#include <string>
#include <stdio.h>

using namespace plugin;

class AmazingTreasureESP {
public:
    AmazingTreasureESP() {
        Events::drawingEvent += [] {
            DrawTreasureInfo();
        };
    }

    static void DrawTreasureInfo() {
        const int TREASURE_MODEL_ID = 12345; 
        
        bool found = false;
        CVector treasurePos = {0.0f, 0.0f, 0.0f};

        CObjectPool* objPool = CPools::ms_pObjectPool;
        if (!objPool) return;

        for (int i = 0; i < objPool->GetSize(); i++) {
            CObject* pObject = objPool->GetAt(i);
            if (pObject) {
                if (pObject->m_nModelIndex == TREASURE_MODEL_ID) {
                    treasurePos = pObject->GetPosition();
                    found = true;
                    break; 
                }
            }
        }

        if (found) {
            char textBuffer[256];
            sprintf(textBuffer, "TREASURE DETECTED | X: %.2f Y: %.2f Z: %.2f", treasurePos.x, treasurePos.y, treasurePos.z);

            CFont::SetScale(0.4f, 0.6f);
            CFont::SetColor(CRGBA(255, 255, 0, 255)); 
            CFont::SetFontStyle(FONT_SUBTITLES);
            CFont::SetProportional(true);
            CFont::SetDropShadowPosition(1);
            CFont::SetDropColor(CRGBA(0, 0, 0, 255));
            CFont::SetAlignment(ALIGN_CENTER);

            float screenX = RsGlobal.maximumWidth / 2.0f;
            float screenY = RsGlobal.maximumHeight - 50.0f; 

            CFont::PrintString(screenX, screenY, textBuffer);
        }
    }
} treasureEsp;
