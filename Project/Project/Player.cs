using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    class Player : Unit
    {
        private Job _job;
        
        public Player() : base()
        {
            _job = Job.Warrior;
        }
        public Player(string name)
        {
            _name = name;
            _job = Job.Warrior;

            _status = new Status();
        }
        public Player(Job job)
        {
            _name = "Unit";
            _job = job;

            _status = new Status(job);
        }
        public Player(string name, Job job)
        {
            _name = name;
            _job = job;

            _status = new Status(job);
        }

        public Job getJob() { return _job; }

        public void setJob(Job job)
        {
            _job = job;
            _status.setTotalStatus(job);
        }

        // 스피드에 따라 데미지 UP
        public int trueDamage(int enemySPD, int enemyDEF)
        {
            if (_status.getSPD() > enemySPD)
                return trueDamage(enemyDEF) * 3 / 2;
            else
                return trueDamage(enemyDEF);
        }
    }
}
