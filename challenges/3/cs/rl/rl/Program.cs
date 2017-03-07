using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace rl
{
    static class Program
    {
        static void Main()
        {

            //TC1
            //            int seats = 4;
            //            int[] preferences = { 1, 2, 3, 4 };


            //TC2
            //           int seats = 3;
            //           int[] preferences = { 2, 3, 4, 5, 6, 7, 4, 7, 8, 8, 12, 12 };


            //TC3
            int seats = 4;
            int[] preferences = { 2, 3, 1, 5, 4 };


            List<Person> persons = new List<Person>();

            for (int i = 0; i < preferences.Length; i++)
            {
                persons.Add(new Person(i, preferences[i] - 1));
            }

            Perform p = new Perform(persons, seats);
            int amountOfParticipants = p.iterate();


            Console.Out.WriteLine("Number of participants who get to go: " + amountOfParticipants);

        }
    }
}