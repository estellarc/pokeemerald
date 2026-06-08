#include "global.h"
#include "tournament_opponent.h"
#include "event_scripts.h"
#include "metaprogram.h"
#include "event_data.h"
#include "constants/event_objects.h"

#define OPPONENT_GFX(graphicsId, ...) { graphicsId, DEFAULT(NUM_OBJ_EVENT_GFX, __VA_ARGS__) }

const struct TournamentOpponent gTournamentOpponents[T_OPPONENT_COUNT] =
{
    [T_OPPONENT_NONE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
    },
    // Gen 1
    [T_OPPONENT_BROCK] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBrock,
    },
    [T_OPPONENT_MISTY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleMisty,
    },
    [T_OPPONENT_LT_SURGE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleLtSurge,
    },
    [T_OPPONENT_ERIKA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleErika,
    },
    [T_OPPONENT_SABRINA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleSabrina,
    },
    [T_OPPONENT_KOGA_AND_JANINE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL, OBJ_EVENT_GFX_MAY_NORMAL),
        .script = EventScript_PWTBattleKogaJanine,
    },
    [T_OPPONENT_BLAINE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBlaine,
    },
    [T_OPPONENT_GIOVANNI] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleGiovanni,
    },
    // Gen2
    [T_OPPONENT_FALKNER] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleFalkner,
    },
    [T_OPPONENT_BUGSY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBugsy,
    },
    [T_OPPONENT_WHITNEY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleWhitney,
    },
    [T_OPPONENT_MORTY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleMorty,
    },
    [T_OPPONENT_CHUCK] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleChuck,
    },
    [T_OPPONENT_JASMINE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleJasmine,
    },
    [T_OPPONENT_PRYCE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattlePryce,
    },
    [T_OPPONENT_CLAIR] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleClair,
    },
    // Gen 3
    [T_OPPONENT_ROXANNE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleRoxanne,
    },
    [T_OPPONENT_BRAWLY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBrawly,
    },
    [T_OPPONENT_WATTSON] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleWattson,
    },
    [T_OPPONENT_FLANNERY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleFlannery,
    },
    [T_OPPONENT_NORMAN] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleNorman,
    },
    [T_OPPONENT_WINONA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleWinona,
    },
    [T_OPPONENT_TATE_AND_LIZA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_TATE, OBJ_EVENT_GFX_LIZA),
        .script = EventScript_PWTBattleTateAndLiza,
    },
    [T_OPPONENT_JUAN] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleJuan,
    },
    // Gen 4
    [T_OPPONENT_ROARK] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleRoark,
    },
    [T_OPPONENT_GARDENIA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleGardenia,
    },
    [T_OPPONENT_MAYLENE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleMaylene,
    },
    [T_OPPONENT_CRASHER_WAKE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleCrasherWake,
    },
    [T_OPPONENT_FANTINA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleFantina,
    },
    [T_OPPONENT_BYRON] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleByron,
    },
    [T_OPPONENT_CANDICE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleCandice,
    },
    [T_OPPONENT_VOLKNER] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleVolkner,
    },
    // Gen 5
    [T_OPPONENT_LENORA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleLenora,
    },
    [T_OPPONENT_BURGH] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBurgh,
    },
    [T_OPPONENT_ELESA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleElesa,
    },
    [T_OPPONENT_CLAY] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleClay,
    },
    [T_OPPONENT_SKYLA] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleSkyla,
    },
    [T_OPPONENT_BRYCEN] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleBrycen,
    },
    [T_OPPONENT_DRAYDEN] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleDrayden,
    },
    [T_OPPONENT_CHEREN] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleCheren, 
    },
    [T_OPPONENT_ROXIE] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleRoxie,
    },
    [T_OPPONENT_MARLON] =
    {
        .graphicsId = OPPONENT_GFX(OBJ_EVENT_GFX_BRENDAN_NORMAL),
        .script = EventScript_PWTBattleMarlon,
    },
};

enum OpponentID GetCurrentOpponent()
{
    switch (VarGet(VAR_GYM_LEADER_BATTLE_COUNT))
    {
        case 0: return VarGet(VAR_GYM_LEADER_1);
        case 1: return VarGet(VAR_GYM_LEADER_1);
        case 2: return VarGet(VAR_GYM_LEADER_1);
    }

    return T_OPPONENT_NONE;
}

void SetupOpponentGfxId(void)
{
    enum OpponentID opponentId = GetCurrentOpponent();
    
    if (IsOpponentADuo(opponentId) == FALSE)
    {
        VarSet(VAR_OBJ_GFX_ID_0, gTournamentOpponents[opponentId].graphicsId[0]);
    }
    else
    {
        VarSet(VAR_OBJ_GFX_ID_1, gTournamentOpponents[opponentId].graphicsId[0]);
        VarSet(VAR_OBJ_GFX_ID_2, gTournamentOpponents[opponentId].graphicsId[1]);
    }
}

bool32 IsOpponentADuo(enum OpponentID opponentId)
{
    const struct TournamentOpponent *opponent = &gTournamentOpponents[opponentId];

    if (opponent->graphicsId[1] >= NUM_OBJ_EVENT_GFX)
        return FALSE;

    return TRUE;
}