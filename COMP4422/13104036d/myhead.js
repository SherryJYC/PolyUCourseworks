if (!Detector.webgl) {
    Detector.addGetWebGLMessage();
}

var container;

var camera, controls, scene, renderer;
var lighting, ambient, keyLight, fillLight, backLight;

var windowHalfX = window.innerWidth / 2;
var windowHalfY = window.innerHeight / 2;

var model;
var leftLight;
var rightLight;
var leftDegree = -45;
var rightDegree = 45;

init();
animate();

function init() {

    container = document.createElement('div');
    document.body.appendChild(container);

    /* Camera */

    camera = new THREE.PerspectiveCamera(90, window.innerWidth / window.innerHeight, 1, 1000);
    camera.position.z = 8;

    /* Scene */

    scene = new THREE.Scene();
    lighting = false;

    ambient = new THREE.AmbientLight(0xffffff, 0.01);
    scene.add(ambient);

    leftRadian = (leftDegree * Math.PI)/180;
    leftLight = new THREE.PointLight(new THREE.Color('hsl(30, 100%, 75%)'), 1.0);
    leftLight.position.set(1000 * Math.sin(leftRadian), 0, 1000 * Math.cos(leftRadian));
    scene.add(leftLight);

    rightRadian = (rightDegree * Math.PI)/180;
    rightLight = new THREE.PointLight(new THREE.Color('hsl(30, 100%, 75%)'), 1.0);
    rightLight.position.set(0, 1000 * Math.sin(rightRadian), 1000 * Math.cos(rightRadian));
    scene.add(rightLight);

    // fillLight = new THREE.PointLight(new THREE.Color('hsl(240, 100%, 75%)'), 0.75);
    // fillLight.position.set(100, 0, 100);

    // backLight = new THREE.PointLight(0xffffff, 1.0);
    // backLight.position.set(100, 0, -100).normalize();

    /* Model */

    var mtlLoader = new THREE.MTLLoader();
    mtlLoader.setBaseUrl('');
    mtlLoader.setPath('');
    mtlLoader.load('myhead.mtl', function (materials) {

        materials.preload();

        materials.materials.default.map.magFilter = THREE.NearestFilter;
        materials.materials.default.map.minFilter = THREE.LinearFilter;

        var objLoader = new THREE.OBJLoader();
        objLoader.setMaterials(materials);
        objLoader.setPath('');
        objLoader.load('myhead.obj', function (object) {

            scene.add(object);
            model = object;

        });

    });

    /* Renderer */

    renderer = new THREE.WebGLRenderer();
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setClearColor(new THREE.Color("hsl(0, 0%, 10%)"));

    container.appendChild(renderer.domElement);

    /* Controls */



    /* Events */

    window.addEventListener('resize', onWindowResize, false);
    window.addEventListener('keydown', onKeyboardEvent, false);

}

function onWindowResize() {

    windowHalfX = window.innerWidth / 2;
    windowHalfY = window.innerHeight / 2;

    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();

    renderer.setSize(window.innerWidth, window.innerHeight);

}

var mode = 'null';

function onKeyboardEvent(e) {
    degree = (5 * Math.PI)/180;

    if (e.keyCode === 65) {
        mode = 'a';
    } else if (e.keyCode === 83) {
        mode = 's';
    } else if (e.keyCode === 37) {
        if (mode === 's')
            model.rotateY(-degree);
        if (mode === 'a' || mode === 's') {
            scene.remove(leftLight);
            leftDegree -= 5;
            leftRadian = (leftDegree * Math.PI)/180;
            leftLight.position.set(1000 * Math.sin(leftRadian), 0, 1000 * Math.cos(leftRadian));
            scene.add(leftLight);
        }
    } else if (e.keyCode === 39) {
        if (mode === 's')
            model.rotateY(degree);
        if (mode === 'a' || mode === 's') {
            leftDegree += 5;
            leftRadian = (leftDegree * Math.PI)/180;
            leftLight.position.set(1000 * Math.sin(leftRadian), 0, 1000 * Math.cos(leftRadian));
            scene.add(leftLight);
        }
    } else if (e.keyCode === 38) {
        if (mode === 's')
            model.rotateX(-degree);
        if (mode === 'a' || mode === 's') {       
            scene.remove(rightLight)
            rightDegree += 5;
            rightRadian = (rightDegree * Math.PI)/180;
            rightLight.position.set(0, 1000 * Math.sin(rightRadian), 1000 * Math.cos(rightRadian));
            scene.add(rightLight);
        }
    } else if (e.keyCode === 40) {
        if (mode === 's')
            model.rotateX(degree);
        if (mode === 'a' || mode === 's') {       
            scene.remove(rightLight)
            rightDegree -= 5;
            rightRadian = (rightDegree * Math.PI)/180;
            rightLight.position.set(0, 1000 * Math.sin(rightRadian), 1000 * Math.cos(rightRadian));
            scene.add(rightLight);
        }
    } else if (e.keyCode === 27) {
        scene.remove(model)
        model.position.set(0,0,0);
        model.rotation.set(0,0,0);
        scene.add(model);

        scene.remove(leftLight);
        leftDegree = -90;
        leftRadian = (leftDegree * Math.PI)/180;
        leftLight.position.set(1000 * Math.sin(leftRadian), 0, 1000 * Math.cos(leftRadian));
        scene.add(leftLight);

        scene.remove(rightLight)
        rightDegree = 90;
        rightRadian = (rightDegree * Math.PI)/180;
        rightLight.position.set(0, 1000 * Math.sin(rightRadian), 1000 * Math.cos(rightRadian));
        scene.add(rightLight);
        mode = 'null';
    }

}

function animate() {

    requestAnimationFrame(animate);


    render();

}

function render() {

    renderer.render(scene, camera);

}
