#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "event_scripts.h"
#include "tournament_logic.h"
#include "tournament_opponent.h"
#include "constants/flags.h"
#include "constants/opponents.h"

struct Roaster
{
    enum OpponentID opponentId;
    u16 flag;
};

static const struct Roaster sKantoGymLeaderRoster[] =
{
    { OPPONENT_BROCK,           FLAG_KANTO_LEADER_BROCK },
    { OPPONENT_MISTY,           FLAG_KANTO_LEADER_MISTY },
    { OPPONENT_LT_SURGE,        FLAG_KANTO_LEADER_LT_SURGE },
    { OPPONENT_ERIKA,           FLAG_KANTO_LEADER_ERIKA },
    { OPPONENT_SABRINA,         FLAG_KANTO_LEADER_SABRINA },
    { OPPONENT_KOGA_AND_JANINE, FLAG_KANTO_LEADER_KOGA_JANINE },
    { OPPONENT_BLAINE,          FLAG_KANTO_LEADER_BLAINE },
    { OPPONENT_GIOVANNI,        FLAG_KANTO_LEADER_GIOVANNI },
};

static const struct Roaster sJohtoGymLeaderRoster[] =
{
    { OPPONENT_FALKNER, FLAG_JOHTO_LEADER_FALKNER },
    { OPPONENT_BUGSY,   FLAG_JOHTO_LEADER_BUGSY },
    { OPPONENT_WHITNEY, FLAG_JOHTO_LEADER_WHITNEY },
    { OPPONENT_MORTY,   FLAG_JOHTO_LEADER_MORTY },
    { OPPONENT_CHUCK,   FLAG_JOHTO_LEADER_CHUCK },
    { OPPONENT_JASMINE, FLAG_JOHTO_LEADER_JASMINE },
    { OPPONENT_PRYCE,   FLAG_JOHTO_LEADER_PRYCE },
    { OPPONENT_CLAIR,   FLAG_JOHTO_LEADER_CLAIR },
};

static const struct Roaster sHoennGymLeaderRoster[] =
{
    { OPPONENT_ROXANNE,       FLAG_HOENN_LEADER_ROXANNE },
    { OPPONENT_BRAWLY,        FLAG_HOENN_LEADER_BRAWLY },
    { OPPONENT_WATTSON,       FLAG_HOENN_LEADER_WATTSON },
    { OPPONENT_FLANNERY_NUTS, FLAG_HOENN_LEADER_FLANNERY },
    { OPPONENT_NORMAN,        FLAG_HOENN_LEADER_NORMAN },
    { OPPONENT_WINONA,        FLAG_HOENN_LEADER_WINONA },
    { OPPONENT_TATE_AND_LIZA, FLAG_HOENN_LEADER_TATE_AND_LIZA },
    { OPPONENT_JUAN,          FLAG_HOENN_LEADER_JUAN },
};

static const struct Roaster sSinnohGymLeaderRoster[] =
{
    { OPPONENT_ROARK,        FLAG_SINNOH_LEADER_ROARK },
    { OPPONENT_GARDENIA,     FLAG_SINNOH_LEADER_GARDENIA },
    { OPPONENT_MAYLENE,      FLAG_SINNOH_LEADER_MAYLENE },
    { OPPONENT_CRASHER_WAKE, FLAG_SINNOH_LEADER_CRASHERWAKE },
    { OPPONENT_FANTINA,      FLAG_SINNOH_LEADER_FANTINA },
    { OPPONENT_BYRON,        FLAG_SINNOH_LEADER_BYRON },
    { OPPONENT_CANDICE,      FLAG_SINNOH_LEADER_CANDICE },
    { OPPONENT_VOLKNER,      FLAG_SINNOH_LEADER_VOLKNER },
};

static const struct Roaster sUnovaGymLeaderRoster[] =
{
    { OPPONENT_LENORA,  FLAG_UNOVA_LEADER_LENORA },
    { OPPONENT_BURGH,   FLAG_UNOVA_LEADER_BURGH },
    { OPPONENT_ELESA,   FLAG_UNOVA_LEADER_ELESA },
    { OPPONENT_CLAY,    FLAG_UNOVA_LEADER_CLAY },
    { OPPONENT_SKYLA,   FLAG_UNOVA_LEADER_SKYLA },
    { OPPONENT_BRYCEN,  FLAG_UNOVA_LEADER_BRYCEN },
    { OPPONENT_DRAYDEN, FLAG_UNOVA_LEADER_DRAYDEN },
    { OPPONENT_CHEREN,  FLAG_UNOVA_LEADER_CHEREN },
    { OPPONENT_ROXIE,   FLAG_UNOVA_LEADER_ROXIE },
    { OPPONENT_MARLON,  FLAG_UNOVA_LEADER_MARLON },
};

#define ROASTER(_roaster, _flag)    \
{                                   \
    .roaster = _roaster,            \
    .count = ARRAY_COUNT(_roaster), \
    .flag = _flag,                  \
}
static const struct RoasterData
{
    const struct Roaster *roaster;
    u32 count;
    u16 flag;
}
sGymLeaderRosters[] =
{
    [ROASTER_GEN1_GYM_LEADERS] = ROASTER(sKantoGymLeaderRoster,  FLAG_COMPLETED_ROSTER_KANTO),
    [ROASTER_GEN2_GYM_LEADERS] = ROASTER(sJohtoGymLeaderRoster,  FLAG_COMPLETED_ROSTER_JOHTO),
    [ROASTER_GEN3_GYM_LEADERS] = ROASTER(sHoennGymLeaderRoster,  FLAG_COMPLETED_ROSTER_HOENN),
    [ROASTER_GEN4_GYM_LEADERS] = ROASTER(sSinnohGymLeaderRoster, FLAG_COMPLETED_ROSTER_SINNOH),
    [ROASTER_GEN5_GYM_LEADERS] = ROASTER(sUnovaGymLeaderRoster,  FLAG_COMPLETED_ROSTER_UNOVA),
};

void ChooseRandomGymLeader(void)
{
    enum TrainerRoaster gen = VarGet(VAR_GENERATION_CTL);
    DebugPrintf("%d", gen);

    u32 countUndefeated = 0;
    u32 leader1 = 0;
    u32 leader2 = 0;
    u32 leader3 = 0;

    for (u32 i = 0; i < sGymLeaderRosters[gen].count; i++)
    {
        if(!FlagGet(sGymLeaderRosters[gen].roaster[i].flag))
            countUndefeated++;
    }
    
    u32 n = RandomUniform(RNG_NONE, 0, countUndefeated - 1);

    for (u32 i = 0; i < sGymLeaderRosters[gen].count; i++)
    {
        if (!FlagGet(sGymLeaderRosters[gen].roaster[i].flag))
        {
            if (n == 0)
            {
                leader3 = i;
                break;
            }
            n--;
        }
    }
    
    do { leader1 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].count - 1); } while (leader1 == leader3);

    do { leader2 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].count - 1); } while (leader2 == leader3 || leader2 == leader1);

    VarSet(VAR_GYM_LEADER_1, sGymLeaderRosters[gen].roaster[leader1].opponentId);
    VarSet(VAR_GYM_LEADER_2, sGymLeaderRosters[gen].roaster[leader2].opponentId);
    VarSet(VAR_GYM_LEADER_3, sGymLeaderRosters[gen].roaster[leader3].opponentId);
};

void Script_goto_pwt_battle_script(struct ScriptContext *ctx)
{
    enum OpponentID opponentId = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    ScriptCall(ctx, gTournamentOpponents[opponentId].script);
}

void SetCompleteRosterFlag(void)
{
    u32 countDefeated = 0;
    enum TrainerRoaster gen = VarGet(VAR_GENERATION_CTL);

    for (u32 i = 0; i < sGymLeaderRosters[gen].count; i++)
    {
        if (FlagGet(sGymLeaderRosters[gen].roaster[i].flag))
            countDefeated++;
    }

    if (countDefeated == sGymLeaderRosters[gen].count)
        FlagSet(sGymLeaderRosters[gen].flag);
}

void CheckForOpponentDuo(void)
{
    enum OpponentID opponentId = GetCurrentOpponent();
    
    if (IsOpponentADuo(opponentId))
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

enum OpponentID GetCurrentOpponent()
{
    switch (VarGet(VAR_GYM_LEADER_BATTLE_COUNT))
    {
        case 1: return VarGet(VAR_GYM_LEADER_1);
        case 2: return VarGet(VAR_GYM_LEADER_2);
        case 3: return VarGet(VAR_GYM_LEADER_3);
    }

    return OPPONENT_NONE;
}

void SetupOpponentGfxId(void)
{
    enum OpponentID opponentId = GetCurrentOpponent();

    Script_RequestEffects(SCREFF_V1);

    if (IsOpponentADuo(opponentId) == TRUE)
    {
        VarSet(VAR_OBJ_GFX_ID_0, gTournamentOpponents[opponentId].graphicsId[0]);
        VarSet(VAR_OBJ_GFX_ID_1, gTournamentOpponents[opponentId].graphicsId[1]);
    }
    else
    {
        VarSet(VAR_OBJ_GFX_ID_0, gTournamentOpponents[opponentId].graphicsId[0]);
    }
}


