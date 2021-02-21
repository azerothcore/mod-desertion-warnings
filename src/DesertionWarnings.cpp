#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

#define DESERTION_ENABLED_CONFIG "DesertionWarnings.Enabled"
#define WARNING_TEXT_CONFIG "DesertionWarnings.WarningText"

class DesertionWarnings : public PlayerScript {
public:

    DesertionWarnings() : PlayerScript("DesertionWarnings") { }

    void OnBattlegroundDesertion(Player* player, const BattlegroundDesertionType type) override
    {
        if (sConfigMgr->GetBoolDefault(DESERTION_ENABLED_CONFIG, false))
        {
            switch (type)
            {
                case BG_DESERTION_TYPE_LEAVE_QUEUE:
                case BG_DESERTION_TYPE_NO_ENTER_BUTTON:
                    ChatHandler(player->GetSession()).PSendSysMessage("%s", sConfigMgr->GetStringDefault(WARNING_TEXT_CONFIG, "").c_str());
                    break;
                default:
                    break;
            }
        }
    }
};

void AddDesertionWarningsScripts() {
    new DesertionWarnings();
}

