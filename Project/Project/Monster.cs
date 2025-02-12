using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    class Monster : Unit
    {
        private Type _type;

        public Monster() : base()
        {
            _type = Type.SkulWarrior;
        }
        public Monster(Type type)
        {
            _type = type;
            _name = StatusValue.MNAME[(int)type];

            _status = new Status(type);
        }

        public Type getType() { return _type; }

        public void setType(Type type)
        {
            _type = type;
            _name = StatusValue.MNAME[(int)type];

            _status.setTotalStatus(type);
        }
    }
}
