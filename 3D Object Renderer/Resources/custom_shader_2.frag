varying vec3 lightDir,normal;


float rand(vec2 n)
{
  return 0.5 + 0.5 * 
     fract(sin(dot(n.xy, vec2(12.9898, 78.233)))* 43758.5453);
}

void main()
{

	float intensity;
	vec4 color;
	
	// normalizing the lights position to be on the safe side
	vec3 l = normalize(vec3(gl_LightSource[0].position));
	
	vec3 n = normalize(normal);

	float red = normalize( rand( n.xy ) );
	float green = normalize( rand( n.yz ) );
	float blue = normalize( rand( n.xz ) );
	color = vec4( red , green , blue , 1.0 );
	
	/*
	intensity = dot(l,n);
	
	if (intensity > 0.95)
		color = vec4(1.0,0.5,0.5,1.0);
	else if (intensity > 0.5)
		color = vec4(0.6,0.3,0.3,1.0);
	else if (intensity > 0.25)
		color = vec4(0.4,0.2,0.2,1.0);
	else
		color = vec4(0.2,0.1,0.1,1.0);
	
	gl_FragColor = color;
	*/
} 