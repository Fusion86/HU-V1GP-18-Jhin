using Jhin.Models;
using System;
using System.Collections.Generic;
using System.Reflection;

using MenuItemsDict = System.Collections.Generic.Dictionary<char, Jhin.Models.MenuItem>;

namespace Jhin
{
    class Program
    {
        static readonly MenuItemsDict m_menuItems = new MenuItemsDict
        {
            { '1', new MenuItem("Draw line", null) },
            { '2', new MenuItem("Draw rectangle", null) },
            { '3', new MenuItem("Draw image from disk", null) },
            { 'q', new MenuItem("Quit", Menu_Quit) }
        };

        static void Main(string[] args)
        {
            // Hook Ctrl+C because we want to some cleanup before we exit
            Console.CancelKeyPress += (s, e) =>
            {
                CleanupBeforeExit();
            };

            // Also hook process exit, for when the user closes the window
            AppDomain.CurrentDomain.ProcessExit += (s, e) =>
            {
                CleanupBeforeExit();
            };

            while (true)
            {
                Console.Clear();

                // Print Jhin ascii art + version number
                Console.WriteLine(@"       _ _     _       ");
                Console.WriteLine(@"      | | |   (_)      ");
                Console.WriteLine(@"      | | |__  _ _ __  ");
                Console.WriteLine(@"  _   | | '_ \| | '_ \ ");
                Console.WriteLine(@" | |__| | | | | | | | |");
                Console.WriteLine(@"  \____/|_| |_|_|_| |_|  v" + Assembly.GetExecutingAssembly().GetName().Version);

                Console.WriteLine(); // Empty line for aesthetics

                // Print menu items
                foreach (KeyValuePair<char, MenuItem> pair in m_menuItems)
                {
                    Console.WriteLine($"{pair.Key} - {pair.Value.Name}");
                }

                ConsoleKeyInfo input = Console.ReadKey();
                Console.Clear(); // Clear console so that the next action can print to it

                // If key exists in m_menuItems
                if (m_menuItems.TryGetValue(input.KeyChar, out var item))
                {
                    if (item.Action != null)
                        item.Action(); // Execute action of the matching MenuItem
                    else
                    {
                        ConsoleColor orig = Console.ForegroundColor;
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("This item hasn't been implemented yet!");
                        Console.ForegroundColor = orig;
                        Console.WriteLine("Press enter to go back to the main menu");
                        Console.ReadLine();
                    }
                }
            }
        }

        static void CleanupBeforeExit()
        {
            // TODO: Everything
        }

        static void Menu_Quit()
        {
            CleanupBeforeExit();
            Environment.Exit(0);
        }
    }
}
