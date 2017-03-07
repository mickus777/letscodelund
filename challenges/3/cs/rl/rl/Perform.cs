using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace rl
{
    public class Perform
    {
        public List<Person> persons;
        public int seats;

        public Perform(List<Person> persons, int seats)
        {
            this.persons = persons;
            this.seats = seats;
        }


        public int iterate()
        {
            if (seats >= persons.Count)
                return persons.Count;

            int steps = 0;

            for (int i = 0; i < persons.Count; i++)
            {
                List<Person> newList = new List<Person>();
                foreach (Person p in persons)
                    newList.Add(p);

                int temp = recursive(newList, i, 0);
                if (temp > steps)
                    steps = temp;
            }

            // assume 1 is going, get required cycle
            // if fits, next person who is not in cycle is assumed going
            // etc.
            // else next person, etc.
            // assume 2 is going
            // etc

            // return list with highest number of participants
            // rejoice

            return steps;
        }

        public int recursive(List<Person> personsNotYetGoing, int currentPerson, int steps)
        {
            List<int> cycle = calculateCycle(currentPerson);
            List<Person> notYetGoing = new List<Person>();
            foreach (Person p in personsNotYetGoing)
                notYetGoing.Add(p);

            if (!(steps + cycle.Count > seats))
            {
                steps += cycle.Count;

                List<Person> onTheTrip = new List<Person>();

                foreach (int i in cycle)
                    foreach (Person p in notYetGoing)
                        if (p.name == i)
                            onTheTrip.Add(p);

                foreach (Person p in onTheTrip)
                    notYetGoing.Remove(p);

                foreach (Person p in notYetGoing)
                    recursive(notYetGoing, p.name, steps);

                return steps;
            }
            return steps;
        }

        public List<int> calculateCycle(int currentPerson)
        {
            List<int> cycle = new List<int>();
            cycle.Add(currentPerson);
            bool continueCycle = true;

            while (continueCycle)
            {
                currentPerson = persons[currentPerson].preference;
                if (cycle.Contains(currentPerson))
                    continueCycle = false;
                else
                    cycle.Add(currentPerson);
            }

            return cycle;
        }
    }
}