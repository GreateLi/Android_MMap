package cn.com.jni.myapplication;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.io.ByteArrayOutputStream;

public class MainActivity extends Activity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);

        Log.e("dd",stringFromJNI());
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void save(View view) {
        mmapWrite("11113311111111sss我的是是@！#", Environment.getExternalStorageDirectory().getPath() ,"crazymo4.txt");
    }

    public void saveBitmap(View view) {
        Bitmap bitmap= BitmapFactory.decodeResource(getResources(),R.mipmap.ic_launcher_test);
        mmapWriteByte(bitmap2Bytes(bitmap), Environment.getExternalStorageDirectory().getAbsolutePath() ,"cmo.png");
    }


    native public static void mmapWrite(String data,String path,String fileName);

    native public static void mmapWriteByte(byte[] data,String path,String fileName);

    /**
     *Bitmap转换成byte[]
     */
    public static byte[] bitmap2Bytes(Bitmap bitmap) {
        ByteArrayOutputStream byteArrOutStream = new ByteArrayOutputStream();
        bitmap.compress(Bitmap.CompressFormat.JPEG, 100, byteArrOutStream);
        return byteArrOutStream.toByteArray();
    }

}
