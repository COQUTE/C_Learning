using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    class Unit
    {
        protected string _name;
        protected Status _status;

        protected Unit()
        {
            _name = "Unit";
            _status = new Status();
        }

        public string getName()   { return _name; }
        public Status getStatus() { return _status; }

        public void setName(string name) { _name = name; }

        // 데미지 계산은 100을 최대로 두고 계산
        public int trueDamage(int enemyDEF)
        {
            Random random = new Random();

            return random.Next(10, 31) + _status.getATK() * (100 - enemyDEF) / 100;
        }
    }
}
