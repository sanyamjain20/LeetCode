class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> td(12, 0);
        td[0] = 0;
        for (int i = 1; i < 12; i++) {
            td[i] += td[i - 1] + days[i-1];
        }

        int aam = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int adm = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        int aad = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        int add = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

        int bam = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        int bdm = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        int bad = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        int bdd = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

        int sa = td[aam - 1] + aad;
        int sb = td[bam - 1] + bad;
        int ea = td[adm - 1] + add;
        int eb = td[bdm - 1] + bdd;

        int s = max(sa, sb);
        int e = min(ea, eb);

        return e - s < 0 ? 0 : e - s + 1;
    }
};