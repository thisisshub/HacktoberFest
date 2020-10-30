from PIL import Image
from PIL import ImageOps
from pathlib import Path
from io import BytesIO


def read_and_transform_image(original: Path, updated: Path):
    with open(original, 'rb') as image_file:
        file_bytes = bytes(image_file.read())
        image = Image.open(BytesIO(file_bytes))
        inverted_image = ImageOps.invert(image)
    with open(updated, 'wb') as update_image_file:
        transformed_image_bytes = BytesIO()
        inverted_image.save(transformed_image_bytes, 'JPEG')
        update_image_file.write(transformed_image_bytes.getvalue())


if __name__ == '__main__':

    original_location = input('Where is your image located? ')
    updated_location = input('Where would you like to save your edited image? ')
    original_path = Path(original_location)
    updated_path = Path(updated_location)
    read_and_transform_image(original_path, updated_path)
