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
    enum TournamentOpponentID opponentId;
    u16 completionFlag;
};

static const struct Roaster sKantoGymLeaderRoster[] =
{
    { T_OPPONENT_BROCK,           FLAG_KANTO_LEADER_BROCK },
    { T_OPPONENT_MISTY,           FLAG_KANTO_LEADER_MISTY },
    { T_OPPONENT_LT_SURGE,        FLAG_KANTO_LEADER_LT_SURGE },
    { T_OPPONENT_ERIKA,           FLAG_KANTO_LEADER_ERIKA },
    { T_OPPONENT_SABRINA,         FLAG_KANTO_LEADER_SABRINA },
    { T_OPPONENT_KOGA_AND_JANINE, FLAG_KANTO_LEADER_KOGA_JANINE },
    { T_OPPONENT_BLAINE,          FLAG_KANTO_LEADER_BLAINE },
    { T_OPPONENT_GIOVANNI,        FLAG_KANTO_LEADER_GIOVANNI },
};

static const struct Roaster sJohtoGymLeaderRoster[] =
{
    { T_OPPONENT_FALKNER, FLAG_JOHTO_LEADER_FALKNER },
    { T_OPPONENT_BUGSY,   FLAG_JOHTO_LEADER_BUGSY },
    { T_OPPONENT_WHITNEY, FLAG_JOHTO_LEADER_WHITNEY },
    { T_OPPONENT_MORTY,   FLAG_JOHTO_LEADER_MORTY },
    { T_OPPONENT_CHUCK,   FLAG_JOHTO_LEADER_CHUCK },
    { T_OPPONENT_JASMINE, FLAG_JOHTO_LEADER_JASMINE },
    { T_OPPONENT_PRYCE,   FLAG_JOHTO_LEADER_PRYCE },
    { T_OPPONENT_CLAIR,   FLAG_JOHTO_LEADER_CLAIR },
};

static const struct Roaster sHoennGymLeaderRoster[] =
{
    { T_OPPONENT_ROXANNE,       FLAG_HOENN_LEADER_ROXANNE },
    { T_OPPONENT_BRAWLY,        FLAG_HOENN_LEADER_BRAWLY },
    { T_OPPONENT_WATTSON,       FLAG_HOENN_LEADER_WATTSON },
    { T_OPPONENT_FLANNERY,      FLAG_HOENN_LEADER_FLANNERY },
    { T_OPPONENT_NORMAN,        FLAG_HOENN_LEADER_NORMAN },
    { T_OPPONENT_WINONA,        FLAG_HOENN_LEADER_WINONA },
    { T_OPPONENT_TATE_AND_LIZA, FLAG_HOENN_LEADER_TATE_AND_LIZA },
    { T_OPPONENT_JUAN,          FLAG_HOENN_LEADER_JUAN },
};

static const struct Roaster sSinnohGymLeaderRoster[] =
{
    { T_OPPONENT_ROARK,        FLAG_SINNOH_LEADER_ROARK },
    { T_OPPONENT_GARDENIA,     FLAG_SINNOH_LEADER_GARDENIA },
    { T_OPPONENT_MAYLENE,      FLAG_SINNOH_LEADER_MAYLENE },
    { T_OPPONENT_CRASHER_WAKE, FLAG_SINNOH_LEADER_CRASHERWAKE },
    { T_OPPONENT_FANTINA,      FLAG_SINNOH_LEADER_FANTINA },
    { T_OPPONENT_BYRON,        FLAG_SINNOH_LEADER_BYRON },
    { T_OPPONENT_CANDICE,      FLAG_SINNOH_LEADER_CANDICE },
    { T_OPPONENT_VOLKNER,      FLAG_SINNOH_LEADER_VOLKNER },
};

static const struct Roaster sUnovaGymLeaderRoster[] =
{
    { T_OPPONENT_LENORA,  FLAG_UNOVA_LEADER_LENORA},
    { T_OPPONENT_BURGH,   FLAG_UNOVA_LEADER_BURGH},
    { T_OPPONENT_ELESA,   FLAG_UNOVA_LEADER_ELESA},
    { T_OPPONENT_CLAY,    FLAG_UNOVA_LEADER_CLAY},
    { T_OPPONENT_SKYLA,   FLAG_UNOVA_LEADER_SKYLA},
    { T_OPPONENT_BRYCEN,  FLAG_UNOVA_LEADER_BRYCEN},
    { T_OPPONENT_DRAYDEN, FLAG_UNOVA_LEADER_DRAYDEN},
    { T_OPPONENT_CHEREN,  FLAG_UNOVA_LEADER_CHEREN},
    { T_OPPONENT_ROXIE,   FLAG_UNOVA_LEADER_ROXIE},
    { T_OPPONENT_MARLON,  FLAG_UNOVA_LEADER_MARLON},
};

static const u16 sRosterCompletionFlags[] =
{
    0,
    FLAG_COMPLETED_ROSTER_KANTO,
    FLAG_COMPLETED_ROSTER_JOHTO,
    FLAG_COMPLETED_ROSTER_HOENN,
    FLAG_COMPLETED_ROSTER_SINNOH,
    FLAG_COMPLETED_ROSTER_UNOVA
};

static const struct RosterStruct {
  struct Roaster *roaster;
  u32 rosterCount;
} sGymLeaderRosters[] = {
    [1] = { sKantoGymLeaderRoster,  ARRAY_COUNT(sKantoGymLeaderRoster) },
    [2] = { sJohtoGymLeaderRoster,  ARRAY_COUNT(sJohtoGymLeaderRoster) },
    [3] = { sHoennGymLeaderRoster,  ARRAY_COUNT(sHoennGymLeaderRoster) },
    [4] = { sSinnohGymLeaderRoster, ARRAY_COUNT(sSinnohGymLeaderRoster) },
    [5] = { sUnovaGymLeaderRoster,  ARRAY_COUNT(sUnovaGymLeaderRoster) }
};

void ChooseRandomGymLeader(void) {
    u32 countUndefeated = 0;
    u32 gen = VarGet(VAR_GENERATION_CTL);
    u32 leader1 = 0;
    u32 leader2 = 0;
    u32 leader3 = 0;


    for (u32 i = 0; i < sGymLeaderRosters[gen].rosterCount; i++)
    {
        if(!FlagGet(sGymLeaderRosters[gen].roaster[i].completionFlag))
            countUndefeated++;
    }
    
    u32 n = RandomUniform(RNG_NONE, 0, countUndefeated - 1);

    for (u32 i = 0; i < sGymLeaderRosters[gen].rosterCount; i++)
    {
        if (!FlagGet(sGymLeaderRosters[gen].roaster[i].completionFlag))
        {
            if (n == 0)
            {
                leader3 = i;
                break;
            }
            n--;
        }
    }
    
    do { leader1 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].rosterCount - 1); } while (leader1 == leader3);

    do { leader2 = RandomUniform(RNG_NONE, 0, sGymLeaderRosters[gen].rosterCount - 1); } while (leader2 == leader3 || leader2 == leader1);

    VarSet(VAR_GYM_LEADER_1, sGymLeaderRosters[gen].roaster[leader1].opponentId);
    VarSet(VAR_GYM_LEADER_2, sGymLeaderRosters[gen].roaster[leader2].opponentId);
    VarSet(VAR_GYM_LEADER_3, sGymLeaderRosters[gen].roaster[leader3].opponentId);

    DebugPrintf("%d, %d, %d", leader1, leader2, leader3);
};

void Script_goto_pwt_battle_script(struct ScriptContext *ctx)
{
    enum TournamentOpponentID opponentId = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);

    ScriptCall(ctx, gTournamentOpponents[opponentId].script);
}

void SetCompleteRosterFlag(void) {
    u32 countDefeated = 0;
    u32 gen = VarGet(VAR_GENERATION_CTL);

    for (u32 i = 0; i < sGymLeaderRosters[gen].rosterCount; i++)
    {
        if(FlagGet(sGymLeaderRosters[gen].roaster[i].completionFlag))
            countDefeated++;
    }

    if(countDefeated == sGymLeaderRosters[gen].rosterCount)
        FlagSet(sRosterCompletionFlags[gen]);
}