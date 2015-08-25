using System;

/*
namespace Mono.Examples
{
   public class HelloWorld
   {
      public static void Run()
      {
          Console.WriteLine("HelloMono: Hello World");
      }
   } 
}
*/

public class HelloWorld
{
    public HelloWorld()
    {
        Console.WriteLine("HelloWorld::HelloWorld");
    }

    ~HelloWorld()
    {
        Console.WriteLine("HelloWorld::~HelloWorld");
    }

    public void OnPreStart()
    {
        Console.WriteLine("HelloWorld::OnPreStart");
    }

    public void OnStart()
    {
        Console.WriteLine("HelloWorld::OnStart");
    }

    public void OnUpdate()
    {
        Console.WriteLine("HelloWorld::OnUpdate");
    }

    public void OnDestroy()
    {
        Console.WriteLine("HelloWorld::OnDestroy");
    }
}
