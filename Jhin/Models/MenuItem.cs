using System;

namespace Jhin.Models
{
    class MenuItem
    {
        public string Name { get; }
        public Action Action { get; }

        public MenuItem(string name, Action action)
        {
            Name = name;
            Action = action;
        }
    }
}
