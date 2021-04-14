using System;
using MatplotLibCLR;

namespace ConsoleApp1
{ 
    class Program
    {
        static void Main(string[] args)
        {
            Graph gr = new Graph();
            //double[] x = gr.Linspace(-2 * Math.PI, 2*Math.PI);
            //double[] y = new double[x.Length];
            //Func<double[], double[]> cube = (xxxx) => {
            //    double[] a = new double[xxxx.Length];
            //    for(int i =0; i < xxxx.Length; i++)
            //    {
            //        a[i] = xxxx[i] * xxxx[i] * xxxx[i];
            //    }
            //    return a;
            //};
            ////Console.WriteLine(cube(3));
            //for (int i=0; i<x.Length; i++)
            //{
            //    y[i] = Math.Sqrt(x[i]);
            //}
            ////int ii = 0;
            ////foreach (var a in x)
            ////{
            ////    Console.WriteLine(ii++);
            ////}

            //gr.Plot(x,cube(x),"-o");
            //gr.Hold(false);
            ////double[,] a = { { 1, 3, 4, 0 ,1}, { 2, 5, 4, 7 ,2}, { 6, 4, 5, 3,3 }, { 2, 2, 1, 7,4 } };
            ////gr.Plot(a);
            //gr.Show();

            double[] t = gr.Iota(0, Math.PI / 50, 10 * Math.PI);
            Func<double[], double[]> sin = (xxxx) => {
                double[] a = new double[xxxx.Length];
                for (int i = 0; i < xxxx.Length; i++)
                {
                    a[i] = Math.Sin(xxxx[i]);
                }
                return a;
            };
            Func<double[], double[]> cos = (xxxx) => {
                double[] a = new double[xxxx.Length];
                for (int i = 0; i < xxxx.Length; i++)
                {
                    a[i] = Math.Cos(xxxx[i]);
                }
                return a;
            };
            double[] st = sin(t);
            double[] ct = cos(t);
            gr.Plot3(st,ct,t);
            gr.Show();
            //Console.WriteLine("Hello World!");
        }
    }
}
