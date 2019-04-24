package com.example.licenta;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;


public class MainActivity extends AppCompatActivity
{
    private boolean manualSauAutomat = false;

    @Override
    protected void onCreate(Bundle savedInstanceState)
	{
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
	
	public void sendGetRequest(String url)
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
	}
	
    public void apasareButonManual(View v)
	{
        RequestQueue queue = Volley.newRequestQueue(this);
        String url;
        if (manualSauAutomat == false) 
		{
            url = "http://192.168.1.126/2/on";
        } 
		else 
		{
            url = "http://192.168.1.126/2/off";
        }
		sendGetRequest(url);
        manualSauAutomat = !manualSauAutomat;
        queue.add(stringRequest);
    }

    public void apasareButonUniversal(View v)
	{
        RequestQueue queue = Volley.newRequestQueue(this);
        String url = "";
        switch (v.getId())
		{
            case (R.id.fata):
			{
                url = "http://192.168.1.126/5/on";
                break;
            }
            case (R.id.spate):
			{
                url = "http://192.168.1.126/15/on";
                break;
            }
            case (R.id.stanga):
			{
                url = "http://192.168.1.126/18/on";
                break;
            }
            case (R.id.dreapta):
			{
                url = "http://192.168.1.126/23/on";
                break;
            }
            case (R.id.sutdrept):
			{
                url = "http://192.168.1.126/19/on";
                break;
            }
            case (R.id.sutstangu):
			{
                url = "http://192.168.1.126/22/on";
                break;
            }
        }
		sendGetRequest(url);
        queue.add(stringRequest);
    }
}