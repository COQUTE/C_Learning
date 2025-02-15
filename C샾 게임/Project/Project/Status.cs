using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    class Status
    {
        private int _HP;
        private int _ATK;
        private int _DEF;
        private int _SPD;

        public Status()
        {
            _HP  = 100;
            _ATK = 100;
            _DEF = 100;
            _SPD = 100;
        }
        public Status(Job job)
        {
            setTotalStatus(job);
        }
        public Status(Type type)
        {
            setTotalStatus(type);
        }

        public int getHP()  { return _HP;  }
        public int getATK() { return _ATK; }
        public int getDEF() { return _DEF; }
        public int getSPD() { return _SPD; }

        public void setHP(int HP)   { _HP  = HP;  }
        public void setATK(int ATK) { _ATK = ATK; }
        public void setDEF(int DEF) { _DEF = DEF; }
        public void setSPD(int SPD) { _SPD = SPD; }

        public void setTotalStatus(Job job)
        {
            _HP  = StatusValue.STAT[(int)job][0];
            _ATK = StatusValue.STAT[(int)job][1];
            _DEF = StatusValue.STAT[(int)job][2];
            _SPD = StatusValue.STAT[(int)job][3];
        }
        public void setTotalStatus(Type type)
        {
            _HP  = StatusValue.MSTAT[(int)type][0];
            _ATK = StatusValue.MSTAT[(int)type][1];
            _DEF = StatusValue.MSTAT[(int)type][2];
            _SPD = StatusValue.MSTAT[(int)type][3];
        }
    }
}
