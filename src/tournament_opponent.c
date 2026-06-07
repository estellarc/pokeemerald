#include "global.h"
#include "tournament_opponent.h"
#include "event_scripts.h"
#include "constants/event_objects.h"

const struct TournamentOpponent gTournamentOpponents[T_OPPONENT_COUNT] =
{
    [T_OPPONENT_NONE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
    },
    // Gen 1
    [T_OPPONENT_BROCK] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBrock,
    },
    [T_OPPONENT_MISTY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleMisty,
    },
    [T_OPPONENT_LT_SURGE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleLtSurge,
    },
    [T_OPPONENT_ERIKA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleErika,
    },
    [T_OPPONENT_SABRINA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleSabrina,
    },
    [T_OPPONENT_KOGA_AND_JANINE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleKogaJanine,
    },
    [T_OPPONENT_BLAINE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBlaine,
    },
    [T_OPPONENT_GIOVANNI] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleGiovanni,
    },
    // Gen2
    [T_OPPONENT_FALKNER] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleFalkner,
    },
    [T_OPPONENT_BUGSY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBugsy,
    },
    [T_OPPONENT_WHITNEY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleWhitney,
    },
    [T_OPPONENT_MORTY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleMorty,
    },
    [T_OPPONENT_CHUCK] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleChuck,
    },
    [T_OPPONENT_JASMINE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleJasmine,
    },
    [T_OPPONENT_PRYCE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattlePryce,
    },
    [T_OPPONENT_CLAIR] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleClair,
    },
    // Gen 3
    [T_OPPONENT_ROXANNE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleRoxanne,
    },
    [T_OPPONENT_BRAWLY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBrawly,
    },
    [T_OPPONENT_WATTSON] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleWattson,
    },
    [T_OPPONENT_FLANNERY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleFlannery,
    },
    [T_OPPONENT_NORMAN] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleNorman,
    },
    [T_OPPONENT_WINONA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleWinona,
    },
    [T_OPPONENT_TATE_AND_LIZA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleTateAndLiza,
    },
    [T_OPPONENT_JUAN] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleJuan,
    },
    [T_OPPONENT_ROARK] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleRoark,
    },
    [T_OPPONENT_GARDENIA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleGardenia,
    },
    [T_OPPONENT_MAYLENE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleMaylene,
    },
    [T_OPPONENT_CRASHER_WAKE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleCrasherWake,
    },
    [T_OPPONENT_FANTINA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleFantina,
    },
    [T_OPPONENT_BYRON] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleByron,
    },
    [T_OPPONENT_CANDICE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleCandice,
    },
    [T_OPPONENT_VOLKNER] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleVolkner,
    },
    [T_OPPONENT_LENORA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleLenora,
    },
    [T_OPPONENT_BURGH] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBurgh,
    },
    [T_OPPONENT_ELESA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleElesa,
    },
    [T_OPPONENT_CLAY] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleClay,
    },
    [T_OPPONENT_SKYLA] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleSkyla,
    },
    [T_OPPONENT_BRYCEN] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleBrycen,
    },
    [T_OPPONENT_DRAYDEN] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleDrayden,
    },
    [T_OPPONENT_CHEREN] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleCheren, 
    },
    [T_OPPONENT_ROXIE] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleRoxie,
    },
    [T_OPPONENT_MARLON] =
    {
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .script = EventScript_PWTBattleMarlon,
    },
};
