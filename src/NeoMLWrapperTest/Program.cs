using System;
using System.IO;

namespace NeoMLWrapperTest
{
    class Program
    {
        static void Main(string[] args)
        {
            // Load neural network and test data
            byte[] dnnInput = File.ReadAllBytes(@"testData/MobileNetV2Cifar10.cnnarch");
            byte[] input = File.ReadAllBytes(@"testData/MobileNetV2Cifar10.input");
            byte[] output = File.ReadAllBytes("testData/MobileNetV2Cifar10.output");
            float[] outputFloat = new float[output.Length / 4];
            Buffer.BlockCopy(output, 0, outputFloat, 0, output.Length);
            Console.WriteLine("Managed CPP Wrapper Test:");
            Console.WriteLine();
            ManagedCppWrapperTest.RunTestWithConsoleOutput(dnnInput, input, outputFloat);        
        }
    }
}
