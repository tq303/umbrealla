import THREE from 'three';

const OrbitControls = require('three-orbit-controls')(THREE);

class Umbrella {
    constructor( ledCount, stripCount ) {

        // setup variables
        this.ledCount      = ledCount;
        this.stripCount    = stripCount;
        this.umbrellaCount = 1;
        this.ledDistance   = 1;

        this.cameraZoom      = 75;

        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 100;
        this.camera.lookAt(new THREE.Vector3(0,0,0));

        this.controls = new OrbitControls(this.camera);

        // material & geometry
        this.material = new THREE.MeshLambertMaterial( {color: 0xffffff, overdraw: 0.5} );

        // build arms and rotate around center axis
        this.umbrella = [];

        for (let i = 0; i < this.umbrellaCount; i++) {

            this.umbrella[i] = this.create();

        }

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        // add to DOM
        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        // begin loop
        this.loop();
    }
    loop() {
        requestAnimationFrame( () => this.loop() );
        this.renderer.render( this.scene, this.camera );
    }
    simpleObject() {
        return {
            lights: [],
            arms:   []
        };
    }
    create() {
        let umbrella = this.simpleObject();

        for (let i = 0; i < this.stripCount; i++) {

            // umbrella.arms[i]   = this.createArms( (360 / this.stripCount) * i );
            umbrella.lights[i] = this.createLights( (360 / this.stripCount) * i );

        }

        return umbrella;
    }
    createArms( angle ) {

        let arm = new THREE.Geometry(),
            x   = Math.cos(this.radians(angle)),
            y   = Math.sin(this.radians(angle)),
            arms;

        // loop each led and place in x,y,z axis
        for (let i = 0; i <= this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ) + 45,
                _z     = Math.cos(this.radians(_angle)) * ( this.ledDistance * i );

            arm.vertices.push(new THREE.Vector3(_x, _y, _z));
        }

        arms = new THREE.Line( arm, this.material );

        this.scene.add( arms );

        return arms;
    }
    createLights( angle ) {

        let x      = Math.cos(this.radians(angle)),
            y      = Math.sin(this.radians(angle)),
            lights = {
                sphere: [],
                point:  []
            },
            geometry = new THREE.SphereGeometry( .5, 8 , 1 );

        // loop each led and place in x,y,z axis
        for (let i = 0; i < this.ledCount; i++) {

            let _x     = x * ( this.ledDistance * i ),
                _y     = y * ( this.ledDistance * i ),
                _angle = (( 90 / this.ledCount ) * i ) + 45,
                _z     = Math.cos(this.radians(_angle)) * ( this.ledDistance * i );

            lights.point[i] = new THREE.PointLight( 0xff0000, 1, 100 );
            lights.point[i].position.set( _x, _y, _z );

            this.scene.add( lights.point[i] );

            lights.sphere[i] = new THREE.Mesh( geometry, this.material );
            lights.sphere[i].position.set( _x, _y, _z );

            this.scene.add( lights.sphere[i] );
        }

        return lights;
    }
    moveCameraUpDwn( amount ) {

        let _y = Math.cos(this.radians(amount)) * this.cameraZoom,
            _z = Math.sin(this.radians(amount)) * this.cameraZoom;

        this.camera.position.y = _y;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    moveCameraLeftRight( amount ) {

        let _x = Math.cos(this.radians(amount)) * this.cameraZoom,
            _z = Math.sin(this.radians(amount)) * this.cameraZoom;

        this.camera.position.x = _x;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    setCameraZoom( zoom ) {
        this.cameraZoom = zoom;
        this.moveCameraUpDwn(0);
        this.moveCameraLeftRight(0);
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
}

export default Umbrella;
