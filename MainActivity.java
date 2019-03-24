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

public class MainActivity extends AppCompatActivity {

    private boolean ManAut=false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void apasareButonManual(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url;
        if(ManAut == false) {
            url = "http://192.168.1.126/2/on";
        }
        else
        {
            url = "http://192.168.1.126/2/off";
        }

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });
        if(ManAut ==false) {
            ManAut = true;
        }
        else
        {
            ManAut=false;
        }
        queue.add(stringRequest);
    }

    public void apasareButonFata(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/5/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }

    public void apasareButonSpate(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/15/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }

    public void apasareButonStanga(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/18/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }
    public void apasareButonDreapta(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/23/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }

    public void apasareButonSutDreptu(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/19/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }

    public void apasareButonSutStangu(View v)
    {
        final TextView textView = (TextView) findViewById(R.id.tv);
        RequestQueue queue = Volley.newRequestQueue(this);
        String url ="http://192.168.1.126/22/on";

// Request a string response from the provided URL.
        StringRequest stringRequest = new StringRequest(Request.Method.GET, url,
                new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {
                        // Display the first 500 characters of the response string.
                        textView.setText("Response is: "+ response.substring(0,500));
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                textView.setText("That didn't work!");
            }
        });

        queue.add(stringRequest);
    }
}
