#ifndef GUARD_TOURNAMENT_LOGIC_H
#define GUARD_TOURNAMENT_LOGIC_H

enum TrainerRoaster
{
    ROASTER_GEN1_GYM_LEADERS = 1,
    ROASTER_GEN2_GYM_LEADERS,
    ROASTER_GEN3_GYM_LEADERS,
    ROASTER_GEN4_GYM_LEADERS,
    ROASTER_GEN5_GYM_LEADERS,
};

void ChooseRandomGymLeader(void);
void SetCompleteRosterFlag(void);
void CheckForOpponentDuo(void);

#endif //GUARD_TOURNAMENT_LOGIC_H
