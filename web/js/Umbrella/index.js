import THREE from 'three';

class Umbrella {
    constructor( ledCount, stripCount ) {

        // setup variables
        this.ledCount   = ledCount;
        this.stripCount = stripCount;
        this.radius = 30;

        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 100;


        // material & geometry
        this.material = new THREE.LineBasicMaterial({
            color: 0xffffff
        });

        // build arms and rotate around center axis
        this.arms = [];

        for (let i = 0; i < this.stripCount; i++) {

            let geometry = this.createArm();

            this.arms[i] = new THREE.Line( geometry, this.material );

            window.console.log( this.arms[i] );

            let angle = ( (360 / this.stripCount) * i ),
                x     = Math.cos(this.radians(angle)) * this.radius,
                y     = Math.sin(this.radians(angle)) * this.radius;

            this.arms[i].rotation.x = x;
            this.arms[i].rotation.y = y;

            // add geometry to scene
            this.scene.add( this.arms[i] );

        }

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        this.loop();
    }
    loop() {
        requestAnimationFrame( () => this.loop() );
        this.renderer.render( this.scene, this.camera );
    }
    createArm() {
        let arm = new THREE.Geometry();

        for (let i = 0; i <= this.ledCount; i++) {

            let angle = ( (90 / this.ledCount) * i ),
                x     = Math.cos(this.radians(angle)) * this.radius,
                y     = Math.sin(this.radians(angle)) * this.radius;

            arm.vertices.push(new THREE.Vector3(x, y, 0));
        }

        return arm;
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
}

export default Umbrella;
