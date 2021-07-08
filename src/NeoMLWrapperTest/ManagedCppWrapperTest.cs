using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using NeoMLWrapper;

namespace NeoMLWrapperTest
{
    public class ManagedCppWrapperTest
    {
        public static void RunTestWithConsoleOutput(byte[] dnnInput, byte[] input, float[] expectedOutput)
        {
            // create NeoML objects with using var to make sure the unmanaged resources are deallocated
            // all NeoML objects are derived from SafeHandle
            using var engine = NeoML.CreateCPUDnnMathEngine();
            using var dnn = engine.CreateDnnFromBuffer(dnnInput);
            using var blob = engine.CreateBlob(DnnBlobType.DBT_Float, batchLength: 1, batchWidth: 1, height: 32, width: 32, depth: 1, channelCount: 3);

            // load test data
            blob.SetData(input);
            dnn.SetInputBlob(index: 0, blob);

            // run the dnn
            dnn.RunOnce();

            // get results and compare it to the reference data set
            using var outputBlob = dnn.GetOutputBlob(index: 0);

            float[] result = outputBlob.GetFloatData();

            Console.WriteLine($"|    Result    |   Expected   |       Delta      |");
            Console.WriteLine($"|--------------|--------------|------------------|");
            for (int i = 0; i < result.Length; i++)
            {
                Console.WriteLine($"| {result[i],-12} | {expectedOutput[i],-12} | {result[i] - expectedOutput[i],-16} |");
            }
        }

        public static void RunTest(byte[] dnnInput, byte[] input, float[] expectedOutput)
        {
            // create NeoML objects with using var to make sure the unmanaged resources are deallocated
            // all NeoML objects are derived from SafeHandle
            using var engine = NeoML.CreateCPUDnnMathEngine();
            using var dnn = engine.CreateDnnFromBuffer(dnnInput);
            using var blob = engine.CreateBlob(DnnBlobType.DBT_Float, batchLength: 1, batchWidth: 1, height: 32, width: 32, depth: 1, channelCount: 3);

            // load test data
            blob.SetData(input);
            dnn.SetInputBlob(index: 0, blob);

            // run the dnn
            dnn.RunOnce();

            // get results and compare it to the reference data set
            using var outputBlob = dnn.GetOutputBlob(index: 0);

            float[] result = outputBlob.GetFloatData();
        }
    }
}
