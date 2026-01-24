import os
import shutil
from pathlib import Path

def shorten_name(name, max_length=63):
    """
    Intelligently shorten a name while keeping it meaningful.
    Preserves unit number and key descriptive words.
    """
    if len(name) <= max_length:
        return name
    
    # Try to preserve the unit number (unit-XXX)
    parts = name.split('-')
    
    # Keep unit number if it exists
    if parts[0] == 'unit' and len(parts) > 1:
        unit_part = f"{parts[0]}-{parts[1]}"
        remaining_budget = max_length - len(unit_part) - 1  # -1 for the hyphen
        
        if remaining_budget > 10:
            # Keep important descriptive words
            descriptive_parts = parts[2:]
            
            # Remove less important words (common connectors)
            filtered_parts = [p for p in descriptive_parts if p not in ['with', 'and', 'using', 'the', 'to', 'in']]
            
            # If we removed connectors but still too long, keep only key words
            if len('-'.join(filtered_parts)) > remaining_budget and len(filtered_parts) > 2:
                filtered_parts = filtered_parts[:2]
            
            short_desc = '-'.join(filtered_parts)[:remaining_budget].rstrip('-')
            return f"{unit_part}-{short_desc}"
    
    # Fallback: just truncate and clean up
    return name[:max_length].rstrip('-')

# Get all .ino files in the current directory
ino_files = list(Path('.').glob('*.ino'))

if not ino_files:
    print("No .ino files found in the current directory.")
else:
    for ino_file in ino_files:
        # Create folder name (without .ino extension)
        original_name = ino_file.stem
        folder_name = shorten_name(original_name)
        
        # Notify if name was shortened
        if original_name != folder_name:
            print(f"⚠️  Shortened: {original_name}")
            print(f"   to: {folder_name} ({len(folder_name)} chars)")
        
        # Create the folder if it doesn't exist
        folder_path = Path(folder_name)
        if not folder_path.exists():
            folder_path.mkdir()
            print(f"Created folder: {folder_name}/")
        else:
            print(f"Folder already exists: {folder_name}/")
        
        # Move the file to the folder
        destination = folder_path / ino_file.name
        shutil.move(str(ino_file), str(destination))
        print(f"Moved {ino_file.name} to {folder_name}/\n")

    print("Done!")
