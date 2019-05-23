package com.example.licenta;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Switch;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;


public class MainActivity extends AppCompatActivity {

    private final String urlPrefix="http://192.168.1.126/";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public StringRequest sendGetRequest(String url)
    {
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>()
                {
                    @Override
                    public void onResponse(String response)
                    {

                    }
                },
                new Response.ErrorListener()
                {
                    @Override
                    public void onErrorResponse(VolleyError error)
                    {

                    }
                });
        return stringRequest;
    }

    public void toggleMode(View v)
    {
        RequestQueue queue = Volley.newRequestQueue(this);
        String url;
        Switch mySwitch = (Switch) findViewById(R.id.switch1);
        if (mySwitch.isChecked())
        {
            url = urlPrefix + "2/on";
        }
        else
        {
            url = urlPrefix + "2/off";
        }
        queue.add(sendGetRequest(url));
    }

    public void universalButon(View v) {
        RequestQueue queue = Volley.newRequestQueue(this);
        String url = "";
        switch (v.getId()) {
            case (R.id.fata): {
                url = urlPrefix + "5/on";
                break;
            }
            case (R.id.spate): {
                url = urlPrefix + "15/on";
                break;
            }
            case (R.id.stanga): {
                url = urlPrefix + "18/on";
                break;
            }
            case (R.id.dreapta): {
                url = urlPrefix + "23/on";
                break;
            }
            case (R.id.sutdrept): {
                url = urlPrefix + "19/on";
                break;
            }
            case (R.id.sutstangu): {
                url = urlPrefix + "22/on";
                break;
            }
        }
        queue.add(sendGetRequest(url));
    }
}
